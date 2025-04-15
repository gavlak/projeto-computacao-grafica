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

    painter.setPen(Qt::gray);

    //marcacoes eixo x
    painter.drawLine(0, 0, width(), 0);
    for (int x = 50; x <= width() - 50; x += 50) {
        painter.drawLine(x, 0, x, 5);
        painter.drawText(x + 2, 15, QString::number(x));
    }

    //marcacoes eixo y
    painter.drawLine(0, 0, 0, height());
    for (int y = 50; y <= height(); y += 50) {
        painter.drawLine(0, y, 5, y);
        painter.drawText(7, y + 5, QString::number(y));
    }

    //tipos visiveis com base nas check boxes
    QSet<QString> tiposVisiveis;

    if (checkPonto && checkPonto->isChecked())
        tiposVisiveis.insert("Ponto");

    if (checkReta && checkReta->isChecked())
        tiposVisiveis.insert("Reta");

    if (checkTriangulo && checkTriangulo->isChecked())
        tiposVisiveis.insert("Triângulo");

    displayFile.desenharTodos(painter, tiposVisiveis);
}

