#ifndef AREADESENHO_H
#define AREADESENHO_H

#include <QFrame>
#include <QPainter>
#include <QList>
#include "objeto.h"
#include "ponto.h"

class AreaDesenho : public QFrame
{
    Q_OBJECT  // Qt precisa disso para o sistema de sinais e slots

public:
    explicit AreaDesenho(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QList<Objeto*> displayFile;
};

#endif // AREADESENHO_H
