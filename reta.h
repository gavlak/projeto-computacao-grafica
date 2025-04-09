#ifndef RETA_H
#define RETA_H

#include "objeto.h"
#include <QPointF>

class Reta : public Objeto {
public:
    QPointF ponto1;
    QPointF ponto2;

    Reta(QString nome, QPointF p1, QPointF p2);

    void desenhar(QPainter &painter) override;
};

#endif // RETA_H
