/*#include "reta.h"
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
}*/

#include "reta.h"
#include "algoritmos.h"

Reta::Reta(QString nome, QPointF p1, QPointF p2) {
    this->nome = nome;
    this->tipo = "Reta";
    this->ponto1 = p1;
    this->ponto2 = p2;
}

void Reta::desenhar(QPainter& painter) {
    // painter.drawLine(ponto1, ponto2); //antigo
    desenharRetaBresenham(painter, ponto1, ponto2);
}


