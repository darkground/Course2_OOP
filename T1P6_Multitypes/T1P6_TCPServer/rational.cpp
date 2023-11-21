#include "rational.h"

int gcd(int n, int d)
{
    return d ? gcd(d, n % d) : n;
}

/*
 * Конструктор рационального числа
 */
TRational::TRational(){
    num = 0;
    deno = 1;
}

/*
 * Конструктор рационального числа из числителя
 */
TRational::TRational(const int& a){
    num = a;
    deno = 1;
}

/*
 * Конструктор рационального числа из числителя и знаменателя
 */
TRational::TRational(const int& a, const int& b){
    num = a;
    deno = b;
}

/*
 * Конструктор рационального числа из сообщения QByteArray
 */
TRational::TRational(const QByteArray& bytearr){
    int p = bytearr.indexOf(SEP);
    num = bytearr.left(p).toInt();
    deno = bytearr.right(bytearr.length()-p-1).toInt();
}

/*
 * Сократить текущую дробь
 */
void TRational::reduct() {
    if (deno == 0)
        throw std::runtime_error("denominator was zero");
    if (deno < 0) {
        num = -num;
        deno = -deno;
    }
    int nod = gcd(abs(num), abs(deno));
    num /= nod;
    deno /= nod;
}

/*
 * Вернуть сокращённую дробь
 */
TRational TRational::reducted() {
    TRational t = TRational(*this);
    t.reduct();
    return t;
}

/*
 * Сложение рациональных чисел
 */
TRational TRational::operator+ (TRational c){
    return TRational(num * c.deno + deno * c.num, deno * c.deno).reducted();
}

/*
 * Вычитание рациональных чисел
 */
TRational TRational::operator- (TRational c){
    return TRational(num * c.deno - deno * c.num, deno * c.deno).reducted();
}

/*
 * Унарный минус
 */
TRational TRational::operator- (){
    return TRational(-num, -deno);
}

/*
 * Сложение с другим рациональным числом и присвоение
 */
TRational TRational::operator+= (TRational c){
    num = num * c.deno + deno * c.num;
    deno = deno * c.deno;
    reduct();
    return *this;
}

/*
 * Вычитание другого рационального числа и присвоение
 */
TRational TRational::operator-= (TRational c){
    num = num * c.deno - deno * c.num;
    deno = deno * c.deno;
    reduct();
    return *this;
}

/*
 * Умножение на другое рациональное число
 */
TRational TRational::operator* (TRational c){
    return TRational(num * c.num, deno * c.deno).reducted();
}

/*
 * Деление на другое рациональное число
 */
TRational TRational::operator/ (TRational c){
    return TRational(num * c.deno, deno * c.num).reducted();
}

/*
 * Равенство двух рациональных чисел
 */
bool TRational::operator==(TRational c){
    return (num == c.num) && (deno == c.deno);
}

/*
 * Неравенство двух рациональных чисел
 */
bool TRational::operator!=(TRational c){
    return (num != c.num) || (deno != c.deno);
}

/*
 * Вывод рационального числа
 */
std::ostream& operator<<(std::ostream& os, TRational c){
    os << c.num << "/" << c.deno;
    return os;
}

/*
 * Вывод рационального числа в QString
 */
QString& operator<<(QString& qs, TRational c){
    qs += QString().setNum(c.num);
    qs += "/";
    qs += QString().setNum(c.deno);
    return qs;
}

TRational::operator QString ()
{
    QString qs;
    qs += QString().setNum(num);
    qs += "/";
    qs += QString().setNum(deno);
    return qs;
}

/*
 * Ввод рационального числа (сначала числитель, потом знаменатель)
 */
std::istream& operator>>(std::istream& is, TRational& c){
    is>>c.num;
    is>>c.deno;
    return is;
}

/*
 * Ввод рационального числа из данных QByteArray
 */
QByteArray& operator>>(QByteArray& arr, TRational& c)
{
    int p = arr.indexOf(TRational::SEP);
    p = arr.indexOf(TRational::SEP, p + 1);
    if (p > 0)
    {
        c = TRational(arr.left(p));
        arr = arr.right(arr.length() - p - 1);
    }
    return arr;
}


