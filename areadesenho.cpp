#include "areadesenho.h"
#include <QDebug>
#include <QMessageBox>
#include "reta.h"
#include "triangulo.h"
#include <QCheckBox>

void AreaDesenho::configurarCheckboxes(QCheckBox* p, QCheckBox* r, QCheckBox* t) {
    checkPonto = p;
    checkReta = r;
    checkTriangulo = t;
}

AreaDesenho::AreaDesenho(QWidget *parent)
    : QFrame(parent)
{
    this->setStyleSheet("background-color: white;");

    // Adiciona os objetos à nova DisplayFile personalizada
    displayFile.adicionar(new Ponto("A", QPointF(50, 50)));
    displayFile.adicionar(new Reta("Minha Reta", QPointF(30, 30), QPointF(150, 80)));

    QVector<QPointF> pts;
    pts << QPointF(100, 100) << QPointF(150, 200) << QPointF(50, 200);
    displayFile.adicionar(new Triangulo("Triângulo 1", pts));
}

void AreaDesenho::paintEvent(QPaintEvent *event)
{

    QFrame::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    /* Define todos os tipos visíveis por padrão
    QSet<QString> tiposVisiveis;
    tiposVisiveis << "Ponto" << "Reta" << "Triângulo";*/

    QSet<QString> tiposVisiveis;

    if (checkPonto && checkPonto->isChecked())
        tiposVisiveis.insert("Ponto");

    if (checkReta && checkReta->isChecked())
        tiposVisiveis.insert("Reta");

    if (checkTriangulo && checkTriangulo->isChecked())
        tiposVisiveis.insert("Triângulo");

    // Chama o método da DisplayFile para desenhar os objetos visíveis
    displayFile.desenharTodos(painter, tiposVisiveis);
}
