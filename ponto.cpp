#include "ponto.h"
#include "matriz.h"

Ponto::Ponto(QString nome, QPointF c)
    : Objeto(nome, "ponto"), coordenada(c) {}

void Ponto::desenhar(QPainter &painter) {
    QPen pen(Qt::red);
    pen.setWidth(6);
    painter.setPen(pen);
    painter.drawPoint(coordenada);
}

void Ponto::transladar(float dx, float dy) {
    Matriz m = Matriz::translacao(dx, dy);
    Matriz p(3, 1);
    p[0][0] = coordenada.x();
    p[1][0] = coordenada.y();
    p[2][0] = 1;

    Matriz resultado = m * p;
    coordenada.setX(resultado[0][0]);
    coordenada.setY(resultado[1][0]);
}

void Ponto::escalar(float sx, float sy) {
    Matriz m = Matriz::escala(sx, sy);
    Matriz p(3, 1);
    p[0][0] = coordenada.x();
    p[1][0] = coordenada.y();
    p[2][0] = 1;

    Matriz resultado = m * p;
    coordenada.setX(resultado[0][0]);
    coordenada.setY(resultado[1][0]);
}

void Ponto::rotacionar(float anguloGraus, const QPointF& centro) {
    Matriz m = Matriz::rotacao(anguloGraus, centro.x(), centro.y());
    Matriz p(3, 1);
    p[0][0] = coordenada.x();
    p[1][0] = coordenada.y();
    p[2][0] = 1;

    Matriz resultado = m * p;
    coordenada.setX(resultado[0][0]);
    coordenada.setY(resultado[1][0]);
}
