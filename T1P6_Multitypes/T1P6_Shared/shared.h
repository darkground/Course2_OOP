#ifndef SHARED_H
#define SHARED_H

#include <QString>

enum messages
{
    /** Запросы серверу **/
    REQ_DETERMINANT = 0,
    REQ_RANK = 1,
    REQ_TRANSPOSE = 2,
    /** Ответы от сервера **/
    ANS_DETERMINANT = 3,
    ANS_RANK = 4,
    ANS_PRINT = 5,
    ANS_ERROR = 6
};

enum modes {
    MODE_RATIONAL = 1,
    MODE_COMPLEX = 2,
    MODE_FLOAT = 3
};

extern const char separator;
QString& operator<< (QString&,const QString&);
QString& operator<< (QString&, const double&);
QByteArray& operator>>(QByteArray&, double&);

#endif // SHARED_H
