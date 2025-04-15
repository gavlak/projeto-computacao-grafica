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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "areadesenho.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir;
    QAction *actionSalvar;
    QAction *actionSobre;
    QWidget *centralwidget;
    AreaDesenho *areaDesenho;
    QPushButton *botaoFechar;
    QCheckBox *checkPonto;
    QCheckBox *checkTriangulo;
    QCheckBox *checkReta;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menu_Arquivo;
    QMenu *menu_Informa_es;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(803, 620);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: white;"));
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName("actionAbrir");
        actionSalvar = new QAction(MainWindow);
        actionSalvar->setObjectName("actionSalvar");
        actionSobre = new QAction(MainWindow);
        actionSobre->setObjectName("actionSobre");
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
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 803, 25));
        menu_Arquivo = new QMenu(menuBar);
        menu_Arquivo->setObjectName("menu_Arquivo");
        menu_Informa_es = new QMenu(menuBar);
        menu_Informa_es->setObjectName("menu_Informa_es");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_Arquivo->menuAction());
        menuBar->addAction(menu_Informa_es->menuAction());
        menu_Arquivo->addAction(actionAbrir);
        menu_Arquivo->addAction(actionSalvar);
        menu_Informa_es->addAction(actionSobre);

        retranslateUi(MainWindow);
        QObject::connect(botaoFechar, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbrir->setText(QCoreApplication::translate("MainWindow", "&Abrir", nullptr));
        actionSalvar->setText(QCoreApplication::translate("MainWindow", "&Salvar e sair", nullptr));
        actionSobre->setText(QCoreApplication::translate("MainWindow", "&Sobre", nullptr));
        botaoFechar->setText(QCoreApplication::translate("MainWindow", "Fechar", nullptr));
        checkPonto->setText(QCoreApplication::translate("MainWindow", "Mostrar pontos", nullptr));
        checkTriangulo->setText(QCoreApplication::translate("MainWindow", "Mostrar triangulos", nullptr));
        checkReta->setText(QCoreApplication::translate("MainWindow", "Mostrar retas", nullptr));
        menu_Arquivo->setTitle(QCoreApplication::translate("MainWindow", "&Arquivo", nullptr));
        menu_Informa_es->setTitle(QCoreApplication::translate("MainWindow", "Detalhes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
