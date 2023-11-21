#ifndef MATRIXSQUARE_H
#define MATRIXSQUARE_H

#include "matrix.h"

class MatrixSquare : public Matrix {
private:
    int size;

public:
    MatrixSquare(int);

    number determ();
    int rank();
};

#endif // MATRIXSQUARE_H
