#ifndef SHARED_H
#define SHARED_H

#include <QString>

enum messages
{
    REQ_DETERMINANT = 0,
    REQ_RANK = 1,
    REQ_TRANSPOSE = 2,
    /***/
    ANS_DETERMINANT = 3,
    ANS_RANK = 4,
    ANS_PRINT = 5,
    ANS_ERROR = 6
};

extern const char separator;
QString& operator<< (QString&,const QString&);

#endif // SHARED_H
