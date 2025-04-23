#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "objeto.h"
#include <QVector>
#include <QPointF>

class Triangulo : public Objeto {
public:
    Triangulo(QString nome, QVector<QPointF> pontos);
    void desenhar(QPainter &painter) override;

    void transladar(float dx, float dy);
    void escalar(float sx, float sy);
    void rotacionar(float anguloGraus, const QPointF& centro);

private:
    QVector<QPointF> pontosTriangulo;
};

#endif
