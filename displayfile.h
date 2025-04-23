#ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include "objeto.h"
#include <QPainter>
#include <QSet>

class DisplayFile {
public:
    struct No {
        Objeto* obj;
        No* proximo;
    };

    DisplayFile();
    ~DisplayFile();

    void adicionar(Objeto* obj);
    void limpar();
    void desenharTodos(QPainter& painter, const QSet<QString>& tiposVisiveis);

    No* getInicio() const { return inicio; }

private:
    No* inicio;
};

#endif
