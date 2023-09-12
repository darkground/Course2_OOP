#include "matrix.h"
#include <QDebug>

matrix::matrix()
{
    qInfo() << "Matrix initialized";
    for (int i = 0; i < MWIDTH * MHEIGHT; i++) {
        qInfo() << this->cells[i];
    }
}
