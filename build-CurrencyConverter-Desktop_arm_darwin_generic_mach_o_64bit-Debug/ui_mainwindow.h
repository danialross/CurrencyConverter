/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QComboBox *fromBox;
    QLabel *fromLabel;
    QLineEdit *input;
    QPushButton *convertButton;
    QPushButton *swapButton;
    QLabel *toLabel;
    QLineEdit *output;
    QComboBox *toBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(412, 323);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(150, 20, 121, 16));
        fromBox = new QComboBox(centralwidget);
        fromBox->setObjectName("fromBox");
        fromBox->setGeometry(QRect(20, 90, 151, 32));
        fromLabel = new QLabel(centralwidget);
        fromLabel->setObjectName("fromLabel");
        fromLabel->setGeometry(QRect(80, 60, 41, 16));
        input = new QLineEdit(centralwidget);
        input->setObjectName("input");
        input->setGeometry(QRect(30, 140, 131, 21));
        convertButton = new QPushButton(centralwidget);
        convertButton->setObjectName("convertButton");
        convertButton->setGeometry(QRect(160, 220, 91, 32));
        swapButton = new QPushButton(centralwidget);
        swapButton->setObjectName("swapButton");
        swapButton->setGeometry(QRect(180, 180, 51, 32));
        toLabel = new QLabel(centralwidget);
        toLabel->setObjectName("toLabel");
        toLabel->setGeometry(QRect(300, 60, 41, 16));
        output = new QLineEdit(centralwidget);
        output->setObjectName("output");
        output->setEnabled(false);
        output->setGeometry(QRect(250, 140, 131, 21));
        toBox = new QComboBox(centralwidget);
        toBox->setObjectName("toBox");
        toBox->setGeometry(QRect(240, 90, 151, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 412, 24));
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
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Currency Converter", nullptr));
        fromLabel->setText(QCoreApplication::translate("MainWindow", "From : ", nullptr));
        convertButton->setText(QCoreApplication::translate("MainWindow", "Convert", nullptr));
        swapButton->setText(QCoreApplication::translate("MainWindow", "Swap", nullptr));
        toLabel->setText(QCoreApplication::translate("MainWindow", "To :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
