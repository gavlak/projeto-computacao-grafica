#include "matriz.h"
#include <iostream>
#include <stdexcept>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

Matriz::Matriz(size_t linhas, size_t colunas, float valorInicial) {
    this->resize(linhas, vector<float>(colunas, valorInicial));
}

size_t Matriz::linhas() const {
    return this->size();
}

size_t Matriz::colunas() const {
    return this->empty() ? 0 : this->at(0).size();
}

void Matriz::imprimir() const {
    for (const auto& linha : *this) {
        for (float valor : linha)
            cout << valor << "\t";
        cout << "\n";
    }
}
float grauParaRad(float grau) {
    return grau * 3.14159265358979323846f / 180.0f;
}

float meuSeno(float x) {
    // x em radianos — aproximação por Taylor até x^5
    return x - (x*x*x)/6.0f + (x*x*x*x*x)/120.0f;
}

float meuCosseno(float x) {
    // x em radianos — aproximação por Taylor até x^4
    return 1.0f - (x*x)/2.0f + (x*x*x*x)/24.0f;
}

Matriz Matriz::operator*(const Matriz& outra) const {
    if (colunas() != outra.linhas())
        throw runtime_error("Dimensões incompatíveis para multiplicação");

    Matriz resultado(linhas(), outra.colunas());

    for (size_t i = 0; i < linhas(); ++i)
        for (size_t j = 0; j < outra.colunas(); ++j)
            for (size_t k = 0; k < colunas(); ++k)
                resultado[i][j] += (*this)[i][k] * outra[k][j];

    return resultado;
}

Matriz Matriz::transposta() const {
    Matriz resultado(colunas(), linhas());
    for (size_t i = 0; i < linhas(); ++i)
        for (size_t j = 0; j < colunas(); ++j)
            resultado[j][i] = (*this)[i][j];
    return resultado;
}

Matriz Matriz::identidade(size_t tamanho) {
    Matriz I(tamanho, tamanho);
    for (size_t i = 0; i < tamanho; ++i)
        I[i][i] = 1.0f;
    return I;
}

Matriz Matriz::translacao(float tx, float ty) {
    Matriz T = identidade(3);
    T[0][2] = tx;
    T[1][2] = ty;
    return T;
}

Matriz Matriz::rotacao(float anguloGraus, float px, float py) {
    // 1. Translada para a origem
    Matriz T1 = Matriz::translacao(-px, -py);

    // 2. Rotaciona na origem
    float rad = grauParaRad(anguloGraus);
    float c = meuCosseno(rad);
    float s = meuSeno(rad);

    Matriz R = Matriz::identidade(3);
    R[0][0] = c;
    R[0][1] = -s;
    R[1][0] = s;
    R[1][1] = c;

    // 3. Translada de volta
    Matriz T2 = Matriz::translacao(px, py);

    // 4. Composição final: T2 * R * T1
    return T2 * R * T1;
}

Matriz Matriz::escala(float sx, float sy) {
    Matriz S = identidade(3);
    S[0][0] = sx;
    S[1][1] = sy;
    return S;
}
