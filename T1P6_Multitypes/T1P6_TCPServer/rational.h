#ifndef TRATIONAL_H
#define TRATIONAL_H

#include <iostream>
#include <QString>

class TRational
{
    int num, deno;
public:
    const static char SEP = ';';

    TRational();
    TRational(const int&);
    TRational(const int&, const int&);
    TRational(const QByteArray&);

    void reduct();
    TRational reducted();
    TRational operator+ (TRational);
    TRational operator+= (TRational);
    TRational operator-= (TRational);
    TRational operator* (TRational);
    TRational operator/ (TRational);
    TRational operator- ();
    TRational operator- (TRational);
    bool operator==(TRational);
    bool operator!=(TRational);

    friend std::ostream& operator<<(std::ostream&,TRational);
    friend QString& operator<<(QString&,TRational);

    friend std::istream& operator>>(std::istream&,TRational&);
    friend QByteArray& operator>>(QByteArray&,TRational&);
    operator QString ();
};

#endif // TRATIONAL_H
