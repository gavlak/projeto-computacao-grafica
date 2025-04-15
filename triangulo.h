#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "objeto.h"
#include <QVector>
#include <QPointF>

class Triangulo : public Objeto {
public:
    QVector<QPointF> pontos;

    Triangulo(QString nome, const QVector<QPointF> &pontos);

    void desenhar(QPainter &painter) override;
};

#endif
