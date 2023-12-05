#ifndef TSAMPLE_H
#define TSAMPLE_H

#include <QPainter>
#include "matrix.h"

class TSample
{
    Matrix<qint16>* matr;
    unsigned sides;
public:
    TSample(Matrix<qint16>*);
    ~TSample();

    void draw(QPainter*, QRect);
};

#endif // TSAMPLE_H
