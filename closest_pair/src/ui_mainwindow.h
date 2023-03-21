/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *find_btn;
    QGroupBox *groupBox;
    QRadioButton *check_brute_force;
    QRadioButton *check_fast_impl;
    QPushButton *clear_btn;
    QPushButton *generate_btn;
    QLabel *label;
    QLabel *label_p1;
    QLabel *label_p2;
    QLabel *label_dis;
    QLabel *label_time;
    QLabel *label_p1_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        find_btn = new QPushButton(centralwidget);
        find_btn->setObjectName(QString::fromUtf8("find_btn"));
        find_btn->setGeometry(QRect(100, 500, 131, 30));
        find_btn->setFocusPolicy(Qt::NoFocus);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(260, 500, 140, 80));
        groupBox->setStyleSheet(QString::fromUtf8("border: 0px;"));
        check_brute_force = new QRadioButton(groupBox);
        check_brute_force->setObjectName(QString::fromUtf8("check_brute_force"));
        check_brute_force->setGeometry(QRect(20, 20, 111, 18));
        check_brute_force->setFocusPolicy(Qt::NoFocus);
        check_fast_impl = new QRadioButton(groupBox);
        check_fast_impl->setObjectName(QString::fromUtf8("check_fast_impl"));
        check_fast_impl->setGeometry(QRect(20, 40, 111, 18));
        check_fast_impl->setFocusPolicy(Qt::NoFocus);
        clear_btn = new QPushButton(centralwidget);
        clear_btn->setObjectName(QString::fromUtf8("clear_btn"));
        clear_btn->setGeometry(QRect(100, 540, 131, 30));
        clear_btn->setFocusPolicy(Qt::NoFocus);
        generate_btn = new QPushButton(centralwidget);
        generate_btn->setObjectName(QString::fromUtf8("generate_btn"));
        generate_btn->setGeometry(QRect(100, 460, 131, 30));
        generate_btn->setFocusPolicy(Qt::NoFocus);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(550, 460, 111, 30));
        QFont font;
        font.setPointSize(17);
        label->setFont(font);
        label_p1 = new QLabel(centralwidget);
        label_p1->setObjectName(QString::fromUtf8("label_p1"));
        label_p1->setGeometry(QRect(470, 500, 151, 30));
        QFont font1;
        font1.setPointSize(12);
        label_p1->setFont(font1);
        label_p2 = new QLabel(centralwidget);
        label_p2->setObjectName(QString::fromUtf8("label_p2"));
        label_p2->setGeometry(QRect(470, 530, 151, 30));
        label_p2->setFont(font1);
        label_dis = new QLabel(centralwidget);
        label_dis->setObjectName(QString::fromUtf8("label_dis"));
        label_dis->setGeometry(QRect(630, 500, 151, 30));
        label_dis->setFont(font1);
        label_time = new QLabel(centralwidget);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(630, 530, 151, 30));
        label_time->setFont(font1);
        label_p1_2 = new QLabel(centralwidget);
        label_p1_2->setObjectName(QString::fromUtf8("label_p1_2"));
        label_p1_2->setGeometry(QRect(280, 490, 151, 30));
        label_p1_2->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(280, 460, 111, 31));
        QFont font2;
        font2.setPointSize(11);
        label_2->setFont(font2);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(400, 465, 101, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        find_btn->setText(QCoreApplication::translate("MainWindow", "Find Closest Pair", nullptr));
        groupBox->setTitle(QString());
        check_brute_force->setText(QCoreApplication::translate("MainWindow", "BruteForce", nullptr));
        check_fast_impl->setText(QCoreApplication::translate("MainWindow", "FastAlgorithm", nullptr));
        clear_btn->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        generate_btn->setText(QCoreApplication::translate("MainWindow", "Randomly Generate", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Result", nullptr));
        label_p1->setText(QCoreApplication::translate("MainWindow", "Point1:", nullptr));
        label_p2->setText(QCoreApplication::translate("MainWindow", "Point2:", nullptr));
        label_dis->setText(QCoreApplication::translate("MainWindow", "Distance:", nullptr));
        label_time->setText(QCoreApplication::translate("MainWindow", "Time:", nullptr));
        label_p1_2->setText(QCoreApplication::translate("MainWindow", "Algorithm", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Point Number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
