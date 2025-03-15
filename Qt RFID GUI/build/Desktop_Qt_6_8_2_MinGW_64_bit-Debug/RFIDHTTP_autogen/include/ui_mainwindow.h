/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *lblTemperature;
    QLabel *lblHumidity;
    QTableView *tableView;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(792, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lblTemperature = new QLabel(centralwidget);
        lblTemperature->setObjectName("lblTemperature");
        lblTemperature->setGeometry(QRect(250, 130, 91, 21));
        lblTemperature->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));
        lblHumidity = new QLabel(centralwidget);
        lblHumidity->setObjectName("lblHumidity");
        lblHumidity->setGeometry(QRect(450, 130, 51, 21));
        lblHumidity->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(100, 200, 571, 221));
        tableView->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 120, 131, 41));
        label->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 127);\n"
"font: 14pt \"Segoe UI\";"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(340, 120, 111, 41));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 127);\n"
"font: 14pt \"Segoe UI\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 20, 461, 51));
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(255, 24, 47);\n"
"font: 20pt \"Segoe UI\";\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 792, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lblTemperature->setText(QCoreApplication::translate("MainWindow", " \302\260C", nullptr));
        lblHumidity->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Temperature :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Humidity:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Employee Entry Management", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
