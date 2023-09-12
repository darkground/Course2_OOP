#ifndef MATRIX_H
#define MATRIX_H

#include "number.h"
#include <iostream>

class matrix
{
private:
    int size;
    number** cells;
public:
    matrix(int);
    ~matrix();
    void init();
    void transp();
    number determ();

    friend std::ostream& operator<< (std::ostream&, matrix&);
};

#endif // MATRIX_H
