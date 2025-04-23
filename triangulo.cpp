#include "triangulo.h"

Triangulo::Triangulo(QString nome, float x1, float y1, float x2, float y2, float x3, float y3) {
    this->nome = nome;
    this->tipo = "Triângulo";

    pontos.push_back({x1, y1, 1.0f});
    pontos.push_back({x2, y2, 1.0f});
    pontos.push_back({x3, y3, 1.0f});
    pontosOriginais = pontos;
}

void Triangulo::desenhar(QPainter &painter) {
    QPen pen(Qt::darkGreen);
    pen.setWidth(2);
    painter.setPen(pen);

    for (int i = 0; i < 3; ++i) {
        QPointF p1(pontos[i][0], pontos[i][1]);
        QPointF p2(pontos[(i + 1) % 3][0], pontos[(i + 1) % 3][1]);
        painter.drawLine(p1, p2);
    }
}

void Triangulo::aplicarTransformacao(const std::vector<std::vector<float>> &matriz) {
    pontos.clear();
    for (const auto& p : pontosOriginais) {
        PontoHomogeneo resultado(3, 0.0f);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                resultado[i] += matriz[i][j] * p[j];
        pontos.push_back(resultado);
    }
}

QPointF Triangulo::centro() const {
    float somaX = 0, somaY = 0;
    for (const auto& p : pontos) {
        somaX += p[0];
        somaY += p[1];
    }
    return QPointF(somaX / pontos.size(), somaY / pontos.size());
}

const std::vector<PontoHomogeneo>& Triangulo::getPontos() const {
    return pontos;
}

void Triangulo::setPontos(const std::vector<PontoHomogeneo>& novosPontos) {
    pontos = novosPontos;
}
