#include "shared.h"

const char separator = ';';

QString& operator<< (QString& m, const QString& s)
{
    m += s;
    m.append(separator);
    return m;
}

/*
 * Перегрузка оператора << для double и QString
 * Необходимо для операций в TApplication::respond
 */
QString& operator<< (QString& m, const double& d)
{
    m += QString().number(d);
    m.append(separator);
    return m;
}

/*
 * Перегрузка оператора >> для double и QByteArray
 * Необходимо для операций в TApplication::make
 */
QByteArray& operator>>(QByteArray& arr, double& d)
{
    int p = arr.indexOf(separator);
    if (p > 0)
    {
        d = arr.left(p).toDouble();
        arr = arr.right(arr.length() - p - 1);
    }
    return arr;
}
