#ifndef RETA_H
#define RETA_H

#include "objeto.h"
#include "tipos.h"
#include <QPainter>

class Reta : public Objeto {
public:
    Reta(QString nome, float x1, float y1, float x2, float y2);

    void desenhar(QPainter &painter) override;
    void aplicarTransformacao(const std::vector<std::vector<float>> &matriz) override;
    QPointF centro() const override;
    const std::vector<PontoHomogeneo>& getPontos() const override;
    void setPontos(const std::vector<PontoHomogeneo>& novosPontos) override;

private:
    std::vector<PontoHomogeneo> pontos;
};

#endif // RETA_H
