#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "objeto.h"
#include "tipos.h"
#include <QPainter>

class Triangulo : public Objeto {
public:
    Triangulo(QString nome, float x1, float y1, float x2, float y2, float x3, float y3);

    void desenhar(QPainter &painter) override;
    void aplicarTransformacao(const std::vector<std::vector<float>> &matriz) override;
    QPointF centro() const override;
    const std::vector<PontoHomogeneo>& getPontos() const override;
    void setPontos(const std::vector<PontoHomogeneo>& novosPontos) override;

private:
    std::vector<PontoHomogeneo> pontos;
};

#endif // TRIANGULO_H
