#include "transformacoes.h"

// Matriz identidade 3x3
std::vector<std::vector<float>> Transformacoes::identidade() {
    return {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
}

// Matriz de translação
std::vector<std::vector<float>> Transformacoes::translacao(float dx, float dy) {
    return {
        {1, 0, dx},
        {0, 1, dy},
        {0, 0, 1}
    };
}

// Multiplicação de duas matrizes 3x3
std::vector<std::vector<float>> Transformacoes::multiplicar(
    const std::vector<std::vector<float>>& A,
    const std::vector<std::vector<float>>& B
    ) {
    std::vector<std::vector<float>> resultado(3, std::vector<float>(3, 0.0f));

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                resultado[i][j] += A[i][k] * B[k][j];

    return resultado;
}

std::vector<std::vector<float>> Transformacoes::escala(float sx, float sy) {
    return {
        {sx, 0,  0},
        {0,  sy, 0},
        {0,  0,  1}
    };
}

