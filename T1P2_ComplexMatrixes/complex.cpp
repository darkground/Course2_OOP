#include "complex.h"

TComplex::TComplex(){
    Re = 0;
    Im = 0;
}

TComplex::TComplex(double r){
    Re = r;
    Im = 0;
}

TComplex::TComplex(double r, double i){
    Re = r;
    Im = i;
}

TComplex TComplex::operator+ (TComplex c){
    return TComplex(Re + c.Re, Im + c.Im);
}

TComplex TComplex::operator- (TComplex c){
    return TComplex(Re - c.Re, Im - c.Im);
}

TComplex TComplex::operator- (){
    return TComplex(-Re, -Im);
}

TComplex TComplex::operator+= (TComplex c){
    return TComplex(Re + c.Re, Im + c.Im);
}

TComplex TComplex::operator-= (TComplex c){
    return TComplex(Re - c.Re, Im - c.Im);
}

TComplex TComplex::operator* (TComplex c){
    return TComplex(Re*c.Re - Im*c.Im, Re*c.Im + Im*c.Re);
}

TComplex TComplex::operator/ (TComplex c){
    double real = (Re*c.Re + Im*c.Im) / (c.Re*c.Re + c.Im*c.Im);
    double imag = (Im*c.Re - Re*c.Im) / (c.Re*c.Re + c.Im*c.Im);
    return TComplex(real, imag);
}

std::ostream& operator<<(std::ostream& os, TComplex c){
    os << c.Re << std::showpos << c.Im << "i" << std::noshowpos;
    return os;
}

std::istream& operator>>(std::istream& is, TComplex& c){
    is>>c.Re;
    is>>c.Im;
    return is;
}

bool TComplex::operator==(TComplex c){
    return (Re == c.Re) && (Im == c.Im);
}

bool TComplex::operator!=(TComplex c){
    return (Re != c.Re) || (Im != c.Im);
}
