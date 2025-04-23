#include "matriz3d.h"

#define PI 3.14159265f

// Conversão de graus para radianos
float grausParaRadianos(float graus) {
    return graus * PI / 180.0f;
}

// Aproximações simples via série de Taylor (baixa ordem)
float senoAprox(float rad) {
    return rad - (rad * rad * rad) / 6.0f;
}

float cossenoAprox(float rad) {
    return 1.0f - (rad * rad) / 2.0f;
}

Matriz3D::Matriz3D() : Matriz(4, 4, 0.0f) {
    for (int i = 0; i < 4; ++i)
        (*this)[i][i] = 1.0f;
}

Matriz3D::Matriz3D(size_t linhas, size_t colunas, float valorInicial)
    : Matriz(linhas, colunas, valorInicial) {}

Matriz3D Matriz3D::identidade() {
    return Matriz3D();
}

Matriz3D Matriz3D::translacao(float tx, float ty, float tz) {
    Matriz3D m;
    m[0][3] = tx;
    m[1][3] = ty;
    m[2][3] = tz;
    return m;
}

Matriz3D Matriz3D::escala(float sx, float sy, float sz) {
    Matriz3D m;
    m[0][0] = sx;
    m[1][1] = sy;
    m[2][2] = sz;
    return m;
}

Matriz3D Matriz3D::rotacaoX(float anguloGraus) {
    float rad = grausParaRadianos(anguloGraus);
    float c = cossenoAprox(rad);
    float s = senoAprox(rad);

    Matriz3D m;
    m[1][1] = c;
    m[1][2] = -s;
    m[2][1] = s;
    m[2][2] = c;
    return m;
}

Matriz3D Matriz3D::rotacaoY(float anguloGraus) {
    float rad = grausParaRadianos(anguloGraus);
    float c = cossenoAprox(rad);
    float s = senoAprox(rad);

    Matriz3D m;
    m[0][0] = c;
    m[0][2] = s;
    m[2][0] = -s;
    m[2][2] = c;
    return m;
}

Matriz3D Matriz3D::rotacaoZ(float anguloGraus) {
    float rad = grausParaRadianos(anguloGraus);
    float c = cossenoAprox(rad);
    float s = senoAprox(rad);

    Matriz3D m;
    m[0][0] = c;
    m[0][1] = -s;
    m[1][0] = s;
    m[1][1] = c;
    return m;
}
