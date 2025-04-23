#ifndef TRANSFORMACOES_H
#define TRANSFORMACOES_H

#include <vector>

class Transformacoes {
public:
    static std::vector<std::vector<float>> identidade();

    static std::vector<std::vector<float>> translacao(float dx, float dy);

    static std::vector<std::vector<float>> multiplicar(
        const std::vector<std::vector<float>>& A,
        const std::vector<std::vector<float>>& B
        );
};

#endif // TRANSFORMACOES_H
