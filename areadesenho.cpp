#include "areadesenho.h"
#include <QDebug> // <-- necessário para usar qDebug()
#include <QMessageBox>


AreaDesenho::AreaDesenho(QWidget *parent)
    : QFrame(parent)
{
    setStyleSheet("background-color: white;");
    displayFile.append(new Ponto("A", QPointF(50, 50)));

    qDebug() << "Construtor AreaDesenho chamado!";
}

void AreaDesenho::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    //QMessageBox::information(this, "Teste", "paintEvent chamado!");

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (const auto& obj : displayFile) {
        obj->desenhar(painter);
    }
}

