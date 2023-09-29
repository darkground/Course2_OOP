#ifndef TCOMPLEX_H
#define TCOMPLEX_H

#include<iostream>

class TComplex
{
    double Re, Im;
public:
    TComplex();
    TComplex(const double&);
    TComplex(const double&, const double&);

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
};

#endif // TCOMPLEX_H
