#ifndef TPHYSICS_H
#define TPHYSICS_H

#include <qmath.h>

class TPhysics
{
    const double dt = 0.02;

protected:
    unsigned l, w;
    double r, v, a;

    double bx, by, bv, ba;

public:
    TPhysics(unsigned l, unsigned w, double r = 25., double v = 20., double a = 45.);

    void step();
    void reset();

    double getBallX();
    double getBallY();
    double getBallVelocity();
    double getBallAngle();
    double getBallSize();
};

#endif // TPHYSICS_H
