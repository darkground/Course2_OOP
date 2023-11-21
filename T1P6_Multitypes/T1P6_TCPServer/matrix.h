#ifndef MATRIX_H
#define MATRIX_H

#include "number.h"
#include <QString>
#include <iostream>

class Matrix {
protected:
    int rows, columns;
    number** cells;

public:
    Matrix(int, int);
    Matrix(Matrix&);

    ~Matrix();
    void init();
    void init(number*);
    void transp();

    friend std::ostream& operator<< (std::ostream&, Matrix&);
    friend QString& operator<< (QString&, Matrix&);
};

#endif // MATRIX_H
