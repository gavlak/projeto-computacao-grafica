#include "reta.h"
#include <QPen>

Reta::Reta(QString nome, QPointF inicio, QPointF fim)
{
    this->nome = nome;
    this->tipo = "Reta";
    this->pontoInicial = inicio;
    this->pontoFinal = fim;
}

void Reta::desenhar(QPainter &painter)
{
    QPen pen(Qt::blue); // cor azul para diferenciar
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(pontoInicial, pontoFinal);
}
