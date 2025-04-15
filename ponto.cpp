#include "ponto.h"

Ponto::Ponto(QString nome, QPointF c) {
    this->nome = nome;
    this->tipo = "Ponto";
    this->coordenada = c;
}

void Ponto::desenhar(QPainter &painter) {
    QPen pen(Qt::red);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawPoint(coordenada);
}
