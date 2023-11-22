#ifndef TCOMPLEX_H
#define TCOMPLEX_H

#include <QString>
#include <iostream>

class TComplex
{
    const static char SEP = ';';

    double Re, Im;
public:
    TComplex();
    TComplex(const double&);
    TComplex(const double&, const double&);
    TComplex(const QByteArray&);

    TComplex operator+ (TComplex);
    TComplex operator+= (TComplex);
    TComplex operator-= (TComplex);
    TComplex operator* (TComplex);
    TComplex operator/ (TComplex);
    TComplex operator- ();
    TComplex operator- (TComplex);
    bool operator==(TComplex);
    bool operator!=(TComplex);

    friend std::ostream& operator<<(std::ostream&,TComplex);
    friend std::istream& operator>>(std::istream&,TComplex&);

    friend QString& operator<<(QString&,TComplex);
    friend QByteArray& operator>>(QByteArray&,TComplex&);
};

#endif // TCOMPLEX_H
