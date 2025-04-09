/*#include "triangulo.h"
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
}*/

#include "triangulo.h"
#include "algoritmos.h"

Triangulo::Triangulo(QString nome, const QVector<QPointF> &pontos) {
    this->nome = nome;
    this->tipo = "Triângulo";
    this->pontos = pontos;
}

void Triangulo::desenhar(QPainter& painter) {
    // painter.drawPolygon(pontos); // antigo
    for (int i = 0; i < pontos.size(); ++i) {
        QPointF p1 = pontos[i];
        QPointF p2 = pontos[(i + 1) % pontos.size()];
        desenharRetaBresenham(painter, p1, p2); // novo
    }
}

