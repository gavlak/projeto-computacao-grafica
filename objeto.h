#ifndef OBJETO_H
#define OBJETO_H

#include <QString>
#include <QPainter>

class Objeto {
public:
    QString nome;
    QString tipo;

    virtual void desenhar(QPainter &painter) = 0; // função abstrata pura
    virtual ~Objeto() = default;
};

#endif // OBJETO_H
