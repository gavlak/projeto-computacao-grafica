#include "triangulo.h"

Triangulo::Triangulo(QString nome, const QVector<QPointF> &pontos) {
    this->nome = nome;
    this->tipo = "Triângulo";
    this->pontos = pontos;
}

void Triangulo::desenhar(QPainter& painter) { //da pra desenhar qualquer outra figura fechada
    QPen pen(Qt::darkGreen);
    pen.setWidth(2);
    painter.setPen(pen);

    for (int i = 0; i < pontos.size(); ++i) {
        QPointF p1 = pontos[i];
        QPointF p2 = pontos[(i + 1) % pontos.size()];
        painter.drawLine(p1, p2);
    }
}

