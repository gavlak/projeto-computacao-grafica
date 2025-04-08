#ifndef RETA_H
#define RETA_H

#include "objeto.h"
#include <QPointF>

class Reta : public Objeto {
public:
    QPointF pontoInicial;
    QPointF pontoFinal;

    Reta(QString nome, QPointF inicio, QPointF fim);

    void desenhar(QPainter &painter) override;
};

#endif // RETA_H
