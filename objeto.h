#ifndef OBJETO_H
#define OBJETO_H

#include <QString>
#include <QPainter>
#include <vector>
#include "tipos.h"

class Objeto {
public:
    QString nome;
    QString tipo;

    virtual ~Objeto() {}

    virtual void desenhar(QPainter &painter) = 0;
    virtual void aplicarTransformacao(const std::vector<std::vector<float>> &matriz) = 0;
    virtual QPointF centro() const = 0;

    // Pontos originais (para garantir transformações acumuladas a partir do estado inicial)
    std::vector<PontoHomogeneo> pontosOriginais;

    // Métodos padrão para acessar e modificar pontos
    virtual const std::vector<PontoHomogeneo>& getPontos() const = 0;
    virtual void setPontos(const std::vector<PontoHomogeneo>& novosPontos) = 0;

    // Salvar os pontos originais (antes de qualquer transformação)
    void salvarPontosOriginais() {
        pontosOriginais = getPontos();
    }
};

#endif // OBJETO_H
