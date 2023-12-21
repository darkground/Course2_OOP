#include "physics.h"
#include <algorithm>

TPhysics::TPhysics(unsigned l, unsigned w, double r, double v, double a) : l(l), w(w), r(r), v(v), a(a) {
    reset();
}

void TPhysics::reset() {
    bx = l / 2;
    by = w / 2;
    bv = v;
    ba = a * (M_PI / 180.0);
}

void TPhysics::step()
{
    bx += bv * std::cos(ba) * dt;
    by += bv * std::sin(ba) * dt;

    if (bx - r < 0 || bx + r > l) {
        ba = M_PI - ba;
        bx = std::clamp(bx, 0., (double)l);
    }

    if (by - r < 0 || by + r > w) {
        ba = -ba;
        by = std::clamp(by, 0., (double)w);
    }
}

double TPhysics::getBallX() {
    return bx;
}

double TPhysics::getBallY() {
    return by;
}

double TPhysics::getBallVelocity() {
    return bv;
}

double TPhysics::getBallAngle() {
    return ba;
}

double TPhysics::getBallSize() {
    return r;
}
