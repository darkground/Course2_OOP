#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include "matrix.h"

class TApplication
{
private:
    matrix* matr;

public:
    int exec();
    int menu();
};

#endif // TAPPLICATION_H
