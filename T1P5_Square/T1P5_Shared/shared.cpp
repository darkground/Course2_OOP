#include "shared.h"

const char separator = ';';

QString& operator<< (QString& m, const QString& s)
{
    m += s;
    m.append(separator);
    return m;
}
