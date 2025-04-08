/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "areadesenho.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    AreaDesenho *areaDesenho;
    QPushButton *botaoFechar;
    QCheckBox *checkPonto;
    QCheckBox *checkTriangulo;
    QCheckBox *checkReta;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(803, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: white;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        areaDesenho = new AreaDesenho(centralwidget);
        areaDesenho->setObjectName("areaDesenho");
        areaDesenho->setGeometry(QRect(9, 19, 611, 531));
        areaDesenho->setStyleSheet(QString::fromUtf8("white"));
        areaDesenho->setFrameShape(QFrame::Shape::Box);
        areaDesenho->setFrameShadow(QFrame::Shadow::Sunken);
        botaoFechar = new QPushButton(centralwidget);
        botaoFechar->setObjectName("botaoFechar");
        botaoFechar->setGeometry(QRect(635, 520, 151, 29));
        botaoFechar->setStyleSheet(QString::fromUtf8("background-color: lightgray;\n"
"color: black;\n"
""));
        checkPonto = new QCheckBox(centralwidget);
        checkPonto->setObjectName("checkPonto");
        checkPonto->setGeometry(QRect(630, 20, 141, 26));
        checkTriangulo = new QCheckBox(centralwidget);
        checkTriangulo->setObjectName("checkTriangulo");
        checkTriangulo->setGeometry(QRect(630, 60, 151, 26));
        checkReta = new QCheckBox(centralwidget);
        checkReta->setObjectName("checkReta");
        checkReta->setGeometry(QRect(630, 100, 111, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 803, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(botaoFechar, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        botaoFechar->setText(QCoreApplication::translate("MainWindow", "Fechar", nullptr));
        checkPonto->setText(QCoreApplication::translate("MainWindow", "Mostrar pontos", nullptr));
        checkTriangulo->setText(QCoreApplication::translate("MainWindow", "Mostrar triangulos", nullptr));
        checkReta->setText(QCoreApplication::translate("MainWindow", "Mostrar retas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
