#include <QApplication>
#include <QStyleFactory>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyle(QStyleFactory::create("Fusion"));

    //aplica o estilo global para menu, checkboxes e QMessageBox
    a.setStyleSheet(R"(
        QMenuBar {
            background-color: white;
            color: black;
        }

        QMenuBar::item:selected {
            background-color: #f0f0f0;
        }

        QMenu {
            background-color: white;
            color: black;
            border: 1px solid gray;
        }

        QMenu::item {
            padding: 5px 20px;
        }

        QMenu::item:selected {
            background-color: #f0f0f0;
            color: black;
        }

        QCheckBox {
            color: black;
        }

        QCheckBox::indicator {
            width: 13px;
            height: 13px;
        }

        QCheckBox::indicator:unchecked {
            border: 1px solid black;
            background-color: white;
        }

        QCheckBox::indicator:checked {
            border: 1px solid black;
            background-color: black;
        }

        /* Corrige visual da QMessageBox */
        QMessageBox {
            background-color: white;
        }

        QMessageBox QLabel {
            color: black;
        }

        QMessageBox QPushButton {
            color: black;
            background-color: #f0f0f0;
            border: 1px solid gray;
            padding: 5px 10px;
        }

        QMessageBox QPushButton:hover {
            background-color: #dcdcdc;
        }
    )");

    MainWindow w;
    w.show();
    return a.exec();
}
