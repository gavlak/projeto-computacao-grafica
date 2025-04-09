#include "algoritmos.h"
#include <cmath>

void desenharRetaBresenham(QPainter& painter, const QPointF& p1, const QPointF& p2) {
    int x1 = int(p1.x());
    int y1 = int(p1.y());
    int x2 = int(p2.x());
    int y2 = int(p2.y());

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    bool trocado = false;

    if (dy > dx) {
        std::swap(dx, dy);
        trocado = true;
    }

    int d = 2 * dy - dx;
    for (int i = 0; i <= dx; ++i) {
        painter.drawPoint(x1, y1);
        if (d > 0) {
            if (trocado)
                x1 += sx;
            else
                y1 += sy;
            d -= 2 * dx;
        }

        if (trocado)
            y1 += sy;
        else
            x1 += sx;

        d += 2 * dy;
    }
}
