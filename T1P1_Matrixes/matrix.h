#ifndef MATRIX_H
#define MATRIX_H

#include "number.h"
#include <iostream>

#define MSIZE 3

class matrix
{
private:
    number cells[MSIZE][MSIZE]{};
public:
    matrix();
    void init();
    void transp();
    void determ();

    friend std::ostream& operator<< (std::ostream&, matrix&);
};

#endif // MATRIX_H
