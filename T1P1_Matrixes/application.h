#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include "matrix.h"

class TApplication
{
private:
    matrix matr{3};

public:
    TApplication();
    int exec();
    int menu();
};

#endif // TAPPLICATION_H
