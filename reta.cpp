#include "reta.h"

Reta::Reta(QString nome, QPointF p1, QPointF p2) {
    this->nome = nome;
    this->tipo = "Reta";
    this->ponto1 = p1;
    this->ponto2 = p2;
}

void Reta::desenhar(QPainter& painter) {
    QPen pen(Qt::blue);
    pen.setWidth(2);
    painter.setPen(pen);

    painter.drawLine(QLineF(ponto1, ponto2));
}


