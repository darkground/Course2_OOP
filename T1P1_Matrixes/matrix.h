#ifndef MATRIX_H
#define MATRIX_H

#include "number.h"

#define MHEIGHT 3
#define MWIDTH 3

class matrix
{
private:
    number cells[MHEIGHT * MWIDTH]{};
public:
    matrix();
};

#endif // MATRIX_H
