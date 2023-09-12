#ifndef MATRIX_H
#define MATRIX_H

#include "number.h"

class matrix
{
private:
    int size;
    number** cells;
public:
    matrix(int);
    ~matrix();
    void print();
    void init();
    void transp();
    number determ();
};

#endif // MATRIX_H
