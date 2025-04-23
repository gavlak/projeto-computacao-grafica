#ifndef OBJETO_H
#define OBJETO_H

#include <QString>
#include <QPainter>
#include <QPointF>

class Objeto {
public:
    QString nome;
    QString tipo;

    Objeto(QString nome, QString tipo) : nome(nome), tipo(tipo) {}

    virtual void desenhar(QPainter &painter) = 0;
    virtual void transladar(float dx, float dy) = 0;
    virtual void escalar(float sx, float sy) = 0;
    virtual void rotacionar(float anguloGraus, const QPointF& centro) = 0;

    virtual ~Objeto() = default;
};

#endif
