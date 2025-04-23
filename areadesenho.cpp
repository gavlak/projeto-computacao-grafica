#include <QDebug>

#include "areadesenho.h"
#include "ponto.h"
#include "reta.h"
#include "triangulo.h"


AreaDesenho::AreaDesenho(QWidget *parent)
    : QFrame(parent)
{
    this->setStyleSheet("background-color: white;");

    displayFile.adicionar(new Ponto("A", QPointF(450, 450)));
    displayFile.adicionar(new Reta("Minha Reta", QPointF(300, 300), QPointF(150, 80)));

    QVector<QPointF> pts;
    pts << QPointF(100, 100) << QPointF(150, 200) << QPointF(50, 200);
    displayFile.adicionar(new Triangulo("Triângulo 1", pts));
}

void AreaDesenho::configurarCheckboxes(QCheckBox* p, QCheckBox* r, QCheckBox* t) {
    checkPonto = p;
    checkReta = r;
    checkTriangulo = t;
}

void AreaDesenho::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QSet<QString> tiposVisiveis;
    if (checkPonto && checkPonto->isChecked()) tiposVisiveis.insert("ponto");
    if (checkReta && checkReta->isChecked()) tiposVisiveis.insert("reta");
    if (checkTriangulo && checkTriangulo->isChecked()) tiposVisiveis.insert("triangulo");

    qDebug() << "Checkbox Ponto:" << (checkPonto ? checkPonto->isChecked() : false);
    qDebug() << "Checkbox Reta:" << (checkReta ? checkReta->isChecked() : false);
    qDebug() << "Checkbox Triangulo:" << (checkTriangulo ? checkTriangulo->isChecked() : false);
    qDebug() << "Tipos visíveis:" << tiposVisiveis;


    displayFile.desenharTodos(painter, tiposVisiveis);
}

void AreaDesenho::aplicarTranslacao(float dx, float dy) {
    DisplayFile::No* atual = displayFile.getInicio();
    while (atual) {
        atual->obj->transladar(dx, dy);
        atual = atual->proximo;
    }
}

void AreaDesenho::aplicarEscala(float sx, float sy) {
    DisplayFile::No* atual = displayFile.getInicio();
    while (atual) {
        atual->obj->escalar(sx, sy);
        atual = atual->proximo;
    }
}

void AreaDesenho::aplicarRotacao(float angulo, const QPointF& centro) {
    DisplayFile::No* atual = displayFile.getInicio();
    while (atual) {
        atual->obj->rotacionar(angulo, centro);
        atual = atual->proximo;
    }
}

