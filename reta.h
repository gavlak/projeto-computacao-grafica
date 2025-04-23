#ifndef RETA_H
#define RETA_H

#include "objeto.h"
#include <QPointF>

class Reta : public Objeto {
public:
    Reta(QString nome, QPointF p1, QPointF p2);
    void desenhar(QPainter &painter) override;

    void transladar(float dx, float dy);
    void escalar(float sx, float sy);
    void rotacionar(float anguloGraus, const QPointF& centro);

private:
    QPointF ponto1;
    QPointF ponto2;
};

#endif
