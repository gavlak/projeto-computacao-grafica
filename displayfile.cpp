#include "displayfile.h"

DisplayFile::DisplayFile() {
    inicio = nullptr;
}

DisplayFile::~DisplayFile() {
    limpar();
}

void DisplayFile::adicionar(Objeto* obj) {
    No* novo = new No{obj, inicio};
    inicio = novo;
}

void DisplayFile::limpar() {
    No* atual = inicio;
    while (atual) {
        No* temp = atual;
        atual = atual->proximo;
        delete temp->obj;
        delete temp;
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
