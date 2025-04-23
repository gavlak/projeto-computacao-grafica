#include "reta.h"
#include "matriz.h"

Reta::Reta(QString nome, QPointF p1, QPointF p2)
    : Objeto(nome, "reta"), ponto1(p1), ponto2(p2) {}

void Reta::desenhar(QPainter &painter) {
    QPen pen(Qt::blue);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(ponto1, ponto2);
}

void Reta::transladar(float dx, float dy) {
    Matriz m = Matriz::translacao(dx, dy);
    for (QPointF& p : { std::ref(ponto1), std::ref(ponto2) }) {
        Matriz pt(3, 1);
        pt[0][0] = p.x();
        pt[1][0] = p.y();
        pt[2][0] = 1;
        Matriz r = m * pt;
        p.setX(r[0][0]);
        p.setY(r[1][0]);
    }
}

void Reta::escalar(float sx, float sy) {
    QPointF centro = (ponto1 + ponto2) / 2;
    Matriz m1 = Matriz::translacao(-centro.x(), -centro.y());
    Matriz esc = Matriz::escala(sx, sy);
    Matriz m2 = Matriz::translacao(centro.x(), centro.y());
    Matriz m = m2 * esc * m1;

    for (QPointF& p : { std::ref(ponto1), std::ref(ponto2) }) {
        Matriz pt(3, 1);
        pt[0][0] = p.x();
        pt[1][0] = p.y();
        pt[2][0] = 1;
        Matriz r = m * pt;
        p.setX(r[0][0]);
        p.setY(r[1][0]);
    }
}

void Reta::rotacionar(float angulo, const QPointF& centro) {
    Matriz m = Matriz::rotacao(angulo, centro.x(), centro.y());
    for (QPointF& p : { std::ref(ponto1), std::ref(ponto2) }) {
        Matriz pt(3, 1);
        pt[0][0] = p.x();
        pt[1][0] = p.y();
        pt[2][0] = 1;
        Matriz r = m * pt;
        p.setX(r[0][0]);
        p.setY(r[1][0]);
    }
}
