#ifndef PONTO_H
#define PONTO_H

#include "objeto.h"
#include <QPointF>

class Ponto : public Objeto {
public:
    Ponto(QString nome, QPointF p);
    void desenhar(QPainter &painter) override;

    void transladar(float dx, float dy);
    void escalar(float sx, float sy);
    void rotacionar(float anguloGraus, const QPointF& centro);

private:
    QPointF coordenada;
};

#endif
