#ifndef AREADESENHO_H
#define AREADESENHO_H

#include <QFrame>
#include <QCheckBox>
#include <QSet>
#include "displayfile.h"

class AreaDesenho : public QFrame
{
    Q_OBJECT

public:
    explicit AreaDesenho(QWidget *parent = nullptr);
    void configurarCheckboxes(QCheckBox* ponto, QCheckBox* reta, QCheckBox* triangulo);

    void aplicarTranslacao(float dx, float dy);
    void aplicarEscala(float sx, float sy);
    void aplicarRotacao(float angulo, const QPointF& centro);


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    DisplayFile displayFile;
    QCheckBox* checkPonto = nullptr;
    QCheckBox* checkReta = nullptr;
    QCheckBox* checkTriangulo = nullptr;
};

#endif
