#ifndef MATRIX_H
#define MATRIX_H

#include "number.h"

#define MSIZE 3

class matrix
{
private:
    number cells[MSIZE][MSIZE]{};
public:
    matrix();
    void print();
    void init();
};

#endif // MATRIX_H