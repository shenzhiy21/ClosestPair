#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "utils.h"
#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    QVector<Point> points;
    Point* points_arr = nullptr;
    bool draw_closest_pair = false;
    std::pair<int, int> closest_pair;
    bool is_pressed = false;
    QPoint pressed_pos;
    Ui::MainWindow *ui;

    void setDefaultLabel();

private slots:
    void generatePoints();
    void getClosestPair();
    void clearPoints();
};
#endif // MAINWINDOW_H
