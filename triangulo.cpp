#include "triangulo.h"
#include <QPen>

Triangulo::Triangulo(QString nome, const QVector<QPointF> &pontos)
{
    this->nome = nome;
    this->tipo = "Triângulo";
    this->pontos = pontos;
}

void Triangulo::desenhar(QPainter &painter)
{
    if (pontos.size() == 3) {
        QPen pen(Qt::darkGreen);
        pen.setWidth(2);
        painter.setPen(pen);

        painter.drawLine(pontos[0], pontos[1]);
        painter.drawLine(pontos[1], pontos[2]);
        painter.drawLine(pontos[2], pontos[0]);
    }
}
