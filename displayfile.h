#ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include "objeto.h"
#include <QPainter>
#include <QSet>

class DisplayFile {
private:
    struct No {
        Objeto* obj;
        No* proximo;
    };

    No* inicio;

public:
    DisplayFile();
    ~DisplayFile();

    void adicionar(Objeto* obj);
    void limpar();
    void desenharTodos(QPainter& painter, const QSet<QString>& tiposVisiveis);
};

#endif
