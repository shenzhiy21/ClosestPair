#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "closest_pair.h"
#include <random>
#include <chrono>
#include <QPainter>
#include <QDebug>
#include <QElapsedTimer>
#include <QMessageBox>

const int MAX_POINTS_TO_DRAW = 10000;
const int MAX_POINTS = 2000000;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);
    this->setMouseTracking(true);
    this->setWindowTitle("Closest Pair");
    ui->check_fast_impl->setChecked(true);

    connect(ui->find_btn, SIGNAL(clicked()), this, SLOT(getClosestPair()));
    connect(ui->generate_btn, SIGNAL(clicked()), this, SLOT(generatePoints()));
    connect(ui->clear_btn, SIGNAL(clicked()), this, SLOT(clearPoints()));
}

MainWindow::~MainWindow()
{
    delete ui;
    if (points_arr != nullptr)
    {
        delete [] points_arr;
    }
}

void MainWindow::generatePoints()
{
    std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

    bool ok = true;
    int number = ui->lineEdit->text().toUInt(&ok);
    if (!ok) return;

    if (number > MAX_POINTS) return;

    points.resize(number);
    for (int i = 0; i < number; i++)
    {
        points[i].x = rng() % 800;
        points[i].y = rng() % 450;
        points[i].id = i;
    }

    draw_closest_pair = false;
    this->setDefaultLabel();
    closest_pair = std::pair<int, int>(-1, -1);

    if (number >= MAX_POINTS_TO_DRAW)
    {
        QMessageBox::information(this, "Message", "Too many points to paint!\nHowever, you can still find the closest pair.", QMessageBox::Ok);
    }

    this->update();
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1));
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(0, 0, this->width(), this->height()-150);

    painter.setBrush(QBrush(Qt::yellow));

    if (points.size() < MAX_POINTS_TO_DRAW)
    {
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i].x;
            int y = points[i].y;
            painter.drawEllipse(QRect(x, y, 3, 3));
        }
        if (draw_closest_pair)
        {
            int p1 = closest_pair.first;
            int p2 = closest_pair.second;
            if (p1 < points.size() && p2 < points.size() && p1 >= 0 && p2 >= 0)
            {
                painter.setBrush(QBrush(Qt::red));
                painter.setPen(QPen(Qt::red, 2));
                painter.drawLine(points[p1].x+2, points[p1].y+2, points[p2].x+2, points[p2].y+2);

                painter.drawEllipse(QRect(points[p1].x, points[p1].y, 5, 5));
                painter.drawEllipse(QRect(points[p2].x, points[p2].y, 5, 5));
            }
        }
    }
}

void MainWindow::getClosestPair()
{
    if (points.size() <= 1)
    {
        return;
    }

    if (points_arr != nullptr)
    {
        delete [] points_arr;
    }

    points_arr = new Point[points.size()];
    for (int i = 0; i < points.size(); i++)
    {
        points_arr[i] = points[i];
    }

    QElapsedTimer timer;
    double elapsed_time = 0;
    if (ui->check_fast_impl->isChecked())
    {
        timer.start();
        closest_pair = fastClosestPair(points_arr, points.size());
        elapsed_time = timer.elapsed();
    }
    else if (ui->check_brute_force->isChecked())
    {
        timer.start();
        closest_pair = bruteForce(points_arr, points.size());
        elapsed_time = timer.elapsed();
    }
    elapsed_time /= 1000;   // convert from milliseconds to seconds

    draw_closest_pair = true;

    int p1_index = closest_pair.first;
    int p2_index = closest_pair.second;
    if (p1_index > p2_index)
    {
        int temp = p1_index;
        p1_index = p2_index;
        p2_index = temp;
    }

    QString log_p1 = "Point1: (" + QString::number(points[p1_index].x) + ", " + QString::number(points[p1_index].y) + ")";
    QString log_p2 = "Point2: (" + QString::number(points[p2_index].x) + ", " + QString::number(points[p2_index].y) + ")";
    QString log_dis = "Distance: " + QString::number(dist(points[p1_index], points[p2_index]));
    QString log_time = "Time: " + QString::number(elapsed_time);
    ui->label_p1->setText(log_p1);
    ui->label_p2->setText(log_p2);
    ui->label_dis->setText(log_dis);
    ui->label_time->setText(log_time);

    this->update();
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        is_pressed = true;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && is_pressed)
    {
        pressed_pos = event->position().toPoint();
        if (pressed_pos.y() > 450) return;
        int num = points.size();
        points.push_back(Point(pressed_pos.x(), pressed_pos.y(), num));
        this->update();
        is_pressed = false;
    }
}

void MainWindow::clearPoints()
{
    points.clear();
    closest_pair = std::pair<int, int>(-1, -1);
    draw_closest_pair = false;
    this->setDefaultLabel();
    this->update();
}

void MainWindow::setDefaultLabel()
{
    ui->label_p1->setText("Point1:");
    ui->label_p2->setText("Point2:");
    ui->label_dis->setText("Distance:");
    ui->label_time->setText("Time:");
}
