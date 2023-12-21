#include "physics.h"
#include <algorithm>

TPhysics::TPhysics(unsigned l, unsigned w, double r, double v, double a) : l(l), w(w), r(r), v(v), a(a) {
    reset();
}

/*
 * Установка начальных значений
 */
void TPhysics::reset() {
    bx = l / 2;
    by = w / 2;
    bv = v;
    ba = a * (M_PI / 180.0);
}

/*
 * Выполнить вычисления движения шара на dt времени вперёд
 */
void TPhysics::step()
{
    bx += bv * std::cos(ba) * dt;
    by += bv * std::sin(ba) * dt;

    if (bx - r < 0 || bx + r > l) { // Left/right wall hit
        ba = M_PI - ba;
        bx = std::clamp(bx, 0., (double)l);
    }

    if (by - r < 0 || by + r > w) { // Upper/bottom wall hit
        ba = -ba;
        by = std::clamp(by, 0., (double)w);
    }
}

/*
 * Позиция X шара
 */
double TPhysics::getBallX() {
    return bx;
}

/*
 * Позиция Y шара
 */
double TPhysics::getBallY() {
    return by;
}

/*
 * Скорость V шара
 */
double TPhysics::getBallVelocity() {
    return bv;
}

/*
 * Угол A шара
 */
double TPhysics::getBallAngle() {
    return ba;
}

/*
 * Радиус R шара
 */
double TPhysics::getBallSize() {
    return r;
}
