#include "reta.h"

Reta::Reta(QString nome, float x1, float y1, float x2, float y2) {
    this->nome = nome;
    this->tipo = "Reta";

    pontos.push_back({x1, y1, 1.0f});
    pontos.push_back({x2, y2, 1.0f});
    pontosOriginais = pontos;
}

void Reta::desenhar(QPainter &painter) {
    QPen pen(Qt::blue);
    pen.setWidth(2);
    painter.setPen(pen);

    QLineF linha(QPointF(pontos[0][0], pontos[0][1]), QPointF(pontos[1][0], pontos[1][1]));
    painter.drawLine(linha);
}

void Reta::aplicarTransformacao(const std::vector<std::vector<float>> &matriz) {
    pontos.clear();
    for (const auto& p : pontosOriginais) {
        PontoHomogeneo resultado(3, 0.0f);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                resultado[i] += matriz[i][j] * p[j];
        pontos.push_back(resultado);
    }
}

QPointF Reta::centro() const {
    float x = (pontos[0][0] + pontos[1][0]) / 2.0f;
    float y = (pontos[0][1] + pontos[1][1]) / 2.0f;
    return QPointF(x, y);
}

const std::vector<PontoHomogeneo>& Reta::getPontos() const {
    return pontos;
}

void Reta::setPontos(const std::vector<PontoHomogeneo>& novosPontos) {
    pontos = novosPontos;
}
