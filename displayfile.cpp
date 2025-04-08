#include "displayfile.h"

DisplayFile::DisplayFile() : inicio(nullptr) {}

DisplayFile::~DisplayFile() {
    limpar();
}

void DisplayFile::adicionar(Objeto* obj) {
    No* novo = new No{obj, nullptr};

    if (!inicio) {
        inicio = novo;
    } else {
        No* atual = inicio;
        while (atual->proximo != nullptr)
            atual = atual->proximo;

        atual->proximo = novo;
    }
}

void DisplayFile::limpar() {
    No* atual = inicio;
    while (atual) {
        No* proximo = atual->proximo;
        delete atual->obj;
        delete atual;
        atual = proximo;
    }
    inicio = nullptr;
}

void DisplayFile::desenharTodos(QPainter& painter, const QSet<QString>& tiposVisiveis) {
    No* atual = inicio;
    while (atual) {
        if (tiposVisiveis.contains(atual->obj->tipo)) {
            atual->obj->desenhar(painter);
        }
        atual = atual->proximo;
    }
}
