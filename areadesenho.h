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
    Q_OBJECT  // Qt precisa disso para o sistema de sinais e slots

public:
    explicit AreaDesenho(QWidget *parent = nullptr);
    void configurarCheckboxes(QCheckBox* ponto, QCheckBox* reta, QCheckBox* triangulo);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    // Comentado: QList<Objeto*> displayFile;
    DisplayFile displayFile;

    // Checkboxes para controle de visibilidade
    QCheckBox* checkPonto = nullptr;
    QCheckBox* checkReta = nullptr;
    QCheckBox* checkTriangulo = nullptr;
};

#endif // AREADESENHO_H
