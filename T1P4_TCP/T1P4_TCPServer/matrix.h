#ifndef MATRIX_H
#define MATRIX_H

#include "number.h"
#include <QString>
#include <iostream>

class matrix
{
private:
    int size;
    number** cells;
public:
    matrix(matrix&);
    matrix(int);
    ~matrix();
    void init();
    void init(number*, int);
    void transp();
    number determ();
    int rank();

    friend std::ostream& operator<< (std::ostream&, matrix&);
    friend QString& operator<< (QString&, matrix&);
};

#endif // MATRIX_H
