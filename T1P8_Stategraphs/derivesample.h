#ifndef TDERIVESAMPLE_H
#define TDERIVESAMPLE_H

#include "sample.h"

class TDeriveSample : public TSample
{
    int active;
public:
    TDeriveSample(Matrix<qint16>*);
    void draw(QPainter*,QRect);
    void newEvent(bool);
};

#endif // TDERIVESAMPLE_H
