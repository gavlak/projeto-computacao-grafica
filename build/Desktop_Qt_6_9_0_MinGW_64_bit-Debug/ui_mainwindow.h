/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
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
    QComboBox *comboTipoFigura_;
    QComboBox *comboBox_2;
    QTextEdit *textEdit;
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
        checkPonto->setGeometry(QRect(630, 190, 141, 26));
        checkTriangulo = new QCheckBox(centralwidget);
        checkTriangulo->setObjectName("checkTriangulo");
        checkTriangulo->setGeometry(QRect(630, 150, 151, 26));
        checkReta = new QCheckBox(centralwidget);
        checkReta->setObjectName("checkReta");
        checkReta->setGeometry(QRect(630, 170, 111, 26));
        comboTipoFigura_ = new QComboBox(centralwidget);
        comboTipoFigura_->addItem(QString());
        comboTipoFigura_->addItem(QString());
        comboTipoFigura_->addItem(QString());
        comboTipoFigura_->setObjectName("comboTipoFigura_");
        comboTipoFigura_->setGeometry(QRect(630, 50, 121, 24));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(630, 110, 121, 24));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(630, 20, 121, 31));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 803, 21));
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
        comboTipoFigura_->setItemText(0, QCoreApplication::translate("MainWindow", "Ponto", nullptr));
        comboTipoFigura_->setItemText(1, QCoreApplication::translate("MainWindow", "Reta", nullptr));
        comboTipoFigura_->setItemText(2, QCoreApplication::translate("MainWindow", "Tri\303\242ngulo", nullptr));

        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Objetos 3D</p></body></html>", nullptr));
        menu_Arquivo->setTitle(QCoreApplication::translate("MainWindow", "&Arquivo", nullptr));
        menu_Informa_es->setTitle(QCoreApplication::translate("MainWindow", "Detalhes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
