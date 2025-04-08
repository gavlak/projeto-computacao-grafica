#include "areadesenho.h"
#include <QDebug> // <-- necessário para usar qDebug()
#include <QMessageBox>
#include "reta.h"
#include "triangulo.h"

AreaDesenho::AreaDesenho(QWidget *parent)
    : QFrame(parent)
{
    setStyleSheet("background-color: white;");
    displayFile.append(new Ponto("A", QPointF(50, 50)));

    displayFile.append(new Reta("Minha Reta", QPointF(30, 30), QPointF(150, 80)));

    QVector<QPointF> pontosTriangulo;
    pontosTriangulo << QPointF(200, 100) << QPointF(250, 200) << QPointF(150, 200);

    displayFile.append(new Triangulo("Triângulo 1", pontosTriangulo));

    //qDebug() << "Construtor AreaDesenho chamado!";
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

