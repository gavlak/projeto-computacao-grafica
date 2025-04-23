#ifndef MATRIZ3D_H
#define MATRIZ3D_H

#include "matriz.h"

class Matriz3D : public Matriz {
public:
    Matriz3D(); // identidade 4x4 por padrão
    Matriz3D(size_t linhas, size_t colunas, float valorInicial = 0.0f);

    static Matriz3D identidade();
    static Matriz3D translacao(float tx, float ty, float tz);
    static Matriz3D escala(float sx, float sy, float sz);
    static Matriz3D rotacaoX(float anguloGraus);
    static Matriz3D rotacaoY(float anguloGraus);
    static Matriz3D rotacaoZ(float anguloGraus);
};

#endif
