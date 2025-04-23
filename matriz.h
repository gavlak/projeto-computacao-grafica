#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>
using namespace std;

//vector from vector
class Matriz : public vector<vector<float>> {
public:
    Matriz(size_t linhas, size_t colunas, float valorInicial = 0.0f);

    size_t linhas() const;
    size_t colunas() const;

    void imprimir() const;
    Matriz operator*(const Matriz& outra) const;
    Matriz transposta() const;

    static Matriz identidade(size_t tamanho);
    static Matriz translacao(float tx, float ty);
    static Matriz rotacao(float anguloGraus, float px, float py);
    static Matriz escala(float sx, float sy);
};

float grauParaRad(float grau);
float meuSeno(float x);
float meuCosseno(float x);

#endif
