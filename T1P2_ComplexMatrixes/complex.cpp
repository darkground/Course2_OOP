#include "complex.h"

const double PRECISION = 0.001;

/*
 * Конструктор комплексного числа
 */
TComplex::TComplex(){
    Re = 0;
    Im = 0;
}

/*
 * Конструктор комплексного числа из реальной части
 */
TComplex::TComplex(const double& r){
    Re = r;
    Im = 0;
}

/*
 * Конструктор комплексного числа из реальной и мнимой части
 */
TComplex::TComplex(const double& r, const double& i){
    Re = r;
    Im = i;
}

/*
 * Сложение комплексных чисел
 */
TComplex TComplex::operator+ (TComplex c){
    return TComplex(Re + c.Re, Im + c.Im);
}

/*
 * Вычитание комплексных чисел
 */
TComplex TComplex::operator- (TComplex c){
    return TComplex(Re - c.Re, Im - c.Im);
}

/*
 * Унарный минус
 */
TComplex TComplex::operator- (){
    return TComplex(-Re, -Im);
}

/*
 * Сложение с другим комплексным числом и присвоение
 */
TComplex TComplex::operator+= (TComplex c){
    Re += c.Re;
    Im += c.Im;
    return *this;
}

/*
 * Вычитание другого комплексного числа и присвоение
 */
TComplex TComplex::operator-= (TComplex c){
    Re -= c.Re;
    Im -= c.Im;
    return *this;
}

/*
 * Умножение на другое комплексное число
 */
TComplex TComplex::operator* (TComplex c){
    return TComplex(Re*c.Re - Im*c.Im, Re*c.Im + Im*c.Re);
}

/*
 * Деление на другое комплексное число
 */
TComplex TComplex::operator/ (TComplex c){
    double real = (Re*c.Re + Im*c.Im) / (c.Re*c.Re + c.Im*c.Im);
    double imag = (Im*c.Re - Re*c.Im) / (c.Re*c.Re + c.Im*c.Im);
    return TComplex(real, imag);
}

/*
 * Вывод комплексного числа
 */
std::ostream& operator<<(std::ostream& os, TComplex c){
    os << c.Re << std::showpos << c.Im << "i" << std::noshowpos;
    return os;
}

/*
 * Ввод комплексного числа (сначала реальная часть, потом мнимая)
 */
std::istream& operator>>(std::istream& is, TComplex& c){
    is>>c.Re;
    is>>c.Im;
    return is;
}

/*
 * Равенство двух комплексных чисел
 */
bool TComplex::operator==(TComplex c){
    return (abs(Re - c.Re) < PRECISION) && (abs(Im - c.Im) < PRECISION);
}

/*
 * Неравенство двух комплексных чисел
 */
bool TComplex::operator!=(TComplex c){
    return (abs(Re - c.Re) > PRECISION) || (abs(Im - c.Im) > PRECISION);
}
