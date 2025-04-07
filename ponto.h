#ifndef PONTO_H
#define PONTO_H

#include "objeto.h"
#include <QPointF>

class Ponto : public Objeto {
public:
    QPointF coordenada;

    Ponto(QString nome, QPointF c);

    void desenhar(QPainter &painter) override;
};

#endif // PONTO_H
