#ifndef TRATIONAL_H
#define TRATIONAL_H

#include <iostream>
#include <QString>

class TRational
{
    int num, deno;
public:
    TRational();
    TRational(const int&);
    TRational(const int&, const int&);

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
};

#endif // TRATIONAL_H
