#include "ponto.h"

Ponto::Ponto(QString nome, float x, float y) {
    this->nome = nome;
    this->tipo = "Ponto";

    PontoHomogeneo p = {x, y, 1.0f};
    pontos.push_back(p);
    pontosOriginais = pontos;
}

void Ponto::desenhar(QPainter &painter) {
    QPointF p(pontos[0][0], pontos[0][1]);
    painter.drawPoint(p);
}

void Ponto::aplicarTransformacao(const std::vector<std::vector<float>> &matriz) {
    // aplica a matriz nos pontosOriginais e atualiza pontos
    pontos.clear();
    for (const auto& p : pontosOriginais) {
        PontoHomogeneo resultado(3, 0.0f);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                resultado[i] += matriz[i][j] * p[j];
        pontos.push_back(resultado);
    }
}

QPointF Ponto::centro() const {
    return QPointF(pontos[0][0], pontos[0][1]);
}

const std::vector<PontoHomogeneo>& Ponto::getPontos() const {
    return pontos;
}

void Ponto::setPontos(const std::vector<PontoHomogeneo>& novosPontos) {
    pontos = novosPontos;
}
