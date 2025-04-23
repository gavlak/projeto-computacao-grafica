#include "triangulo.h"
#include "matriz.h"

Triangulo::Triangulo(QString nome, QVector<QPointF> pontos)
    : Objeto(nome, "triangulo"), pontosTriangulo(pontos) {}

void Triangulo::desenhar(QPainter &painter) {
    if (pontosTriangulo.size() == 3) {
        QPen pen(Qt::darkGreen);
        pen.setWidth(2);
        painter.setPen(pen);
        painter.drawPolygon(pontosTriangulo.constData(), 3);
    }
}

void Triangulo::transladar(float dx, float dy) {
    Matriz m = Matriz::translacao(dx, dy);
    for (QPointF& p : pontosTriangulo) {
        Matriz pt(3, 1);
        pt[0][0] = p.x();
        pt[1][0] = p.y();
        pt[2][0] = 1;
        Matriz r = m * pt;
        p.setX(r[0][0]);
        p.setY(r[1][0]);
    }
}

void Triangulo::escalar(float sx, float sy) {
    QPointF centro(0, 0);
    for (const QPointF& p : pontosTriangulo) {
        centro += p;
    }
    centro /= 3;

    Matriz m1 = Matriz::translacao(-centro.x(), -centro.y());
    Matriz esc = Matriz::escala(sx, sy);
    Matriz m2 = Matriz::translacao(centro.x(), centro.y());
    Matriz m = m2 * esc * m1;

    for (QPointF& p : pontosTriangulo) {
        Matriz pt(3, 1);
        pt[0][0] = p.x();
        pt[1][0] = p.y();
        pt[2][0] = 1;
        Matriz r = m * pt;
        p.setX(r[0][0]);
        p.setY(r[1][0]);
    }
}

void Triangulo::rotacionar(float angulo, const QPointF& centro) {
    Matriz m = Matriz::rotacao(angulo, centro.x(), centro.y());
    for (QPointF& p : pontosTriangulo) {
        Matriz pt(3, 1);
        pt[0][0] = p.x();
        pt[1][0] = p.y();
        pt[2][0] = 1;
        Matriz r = m * pt;
        p.setX(r[0][0]);
        p.setY(r[1][0]);
    }
}
