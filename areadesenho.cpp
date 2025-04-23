#include "areadesenho.h"
#include <QDebug>
#include <QMessageBox>
#include "reta.h"
#include "triangulo.h"
#include "ponto.h"
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

    // Adiciona objetos com os novos construtores baseados em coordenadas float
    displayFile.adicionar(new Ponto("ponto1", 450.0f, 450.0f));
    displayFile.adicionar(new Reta("reta1", 300, 300, 150, 80)); // em vez de passar QPointF
    displayFile.adicionar(new Triangulo("triangulo1", 100, 100, 150, 200, 50, 200));
}

void AreaDesenho::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(Qt::gray);

    // Marcação eixo X
    painter.drawLine(0, 0, width(), 0);
    for (int x = 50; x <= width() - 50; x += 50) {
        painter.drawLine(x, 0, x, 5);
        painter.drawText(x + 2, 15, QString::number(x));
    }

    // Marcação eixo Y
    painter.drawLine(0, 0, 0, height());
    for (int y = 50; y <= height(); y += 50) {
        painter.drawLine(0, y, 5, y);
        painter.drawText(7, y + 5, QString::number(y));
    }

    // Verifica os tipos visíveis com base nas checkboxes
    QSet<QString> tiposVisiveis;

    if (checkPonto && checkPonto->isChecked())
        tiposVisiveis.insert("Ponto");

    if (checkReta && checkReta->isChecked())
        tiposVisiveis.insert("Reta");

    if (checkTriangulo && checkTriangulo->isChecked())
        tiposVisiveis.insert("Triângulo");

    displayFile.desenharTodos(painter, tiposVisiveis);
}

DisplayFile* AreaDesenho::getDisplayFile() {
    return &displayFile;
}

