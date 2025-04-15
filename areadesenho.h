#ifndef AREADESENHO_H
#define AREADESENHO_H

#include <QFrame>
#include <QPainter>
#include <QList>
#include "objeto.h"
#include "ponto.h"
#include "displayfile.h"
#include <QCheckBox>

class AreaDesenho : public QFrame
{
    Q_OBJECT

public:
    explicit AreaDesenho(QWidget *parent = nullptr);
    void configurarCheckboxes(QCheckBox* ponto, QCheckBox* reta, QCheckBox* triangulo);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    //QList<Objeto*> displayFile; implementacao antiga
    DisplayFile displayFile;

    QCheckBox* checkPonto = nullptr;
    QCheckBox* checkReta = nullptr;
    QCheckBox* checkTriangulo = nullptr;
};

#endif
