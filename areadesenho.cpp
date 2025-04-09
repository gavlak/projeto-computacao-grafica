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
    displayFile.adicionar(new Ponto("A", QPointF(450, 450)));
    displayFile.adicionar(new Reta("Minha Reta", QPointF(300, 300), QPointF(150, 80)));

    QVector<QPointF> pts;
    pts << QPointF(100, 100) << QPointF(150, 200) << QPointF(50, 200);
    displayFile.adicionar(new Triangulo("Triângulo 1", pts));
}
void AreaDesenho::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // ====== DESENHA EIXOS (X e Y) ======
    painter.setPen(Qt::gray);

    // Eixo X
    painter.drawLine(0, 0, width(), 0);  // linha no topo
    for (int x = 0; x <= width(); x += 50) {
        painter.drawLine(x, 0, x, 5);
        if (x != 0)
            painter.drawText(x + 2, 15, QString::number(x));
    }

    // Eixo Y
    painter.drawLine(0, 0, 0, height()); // linha na esquerda
    for (int y = 0; y <= height(); y += 50) {
        painter.drawLine(0, y, 5, y); // marcações
        painter.drawText(7, y + 5, QString::number(y)); // valores
    }

    // ====== FILTRA OS TIPOS VISÍVEIS COM BASE NAS CHECKBOXES ======
    QSet<QString> tiposVisiveis;

    if (checkPonto && checkPonto->isChecked())
        tiposVisiveis.insert("Ponto");

    if (checkReta && checkReta->isChecked())
        tiposVisiveis.insert("Reta");

    if (checkTriangulo && checkTriangulo->isChecked())
        tiposVisiveis.insert("Triângulo");

    // ====== DESENHA OS OBJETOS VISÍVEIS ======
    displayFile.desenharTodos(painter, tiposVisiveis);
}

