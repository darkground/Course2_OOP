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
 * Конструктор комплексного числа из сообщения QByteArray
 */
TComplex::TComplex(const QByteArray& bytearr){
    int p = bytearr.indexOf(SEP);
    Re = bytearr.left(p).toInt();
    Im = bytearr.right(bytearr.length()-p-1).toInt();
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

/*
 * Вывод комплексного числа в QString
 */
QString& operator<<(QString& qs, TComplex c){
    qs += QString().setNum(c.Re);
    if (c.Im >= 0)
        qs += '+';
    qs += QString().setNum(c.Im);
    qs += "i";
    return qs;
}

/*
 * Ввод рационального числа из данных QByteArray
 */
QByteArray& operator>>(QByteArray& arr, TComplex& c)
{
    int p = arr.indexOf(TComplex::SEP);
    p = arr.indexOf(TComplex::SEP, p + 1);
    if (p > 0)
    {
        c = TComplex(arr.left(p));
        arr = arr.right(arr.length() - p - 1);
    }
    return arr;
}
