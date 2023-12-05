#ifndef MATRIX_H
#define MATRIX_H

#include <QString>
#include <iostream>
#include <iomanip>

using namespace std;

template <class number> class Matrix {
protected:
    int rows, columns;
    number** cells;

public:
    Matrix(int, int);
    Matrix(Matrix&);

    ~Matrix();
    void init();
    void init(number*);
    void transp();
    unsigned getSizeX();
    unsigned getSizeY();
    number get(unsigned, unsigned);

    template <class T> friend std::ostream& operator<< (std::ostream&, Matrix<T>&);
    template <class T> friend QString& operator<< (QString&, Matrix<T>&);
};

/*
 * Конструктор класса Matrix
 * Создать матрицу размера r x c
 */
template <class T>
Matrix<T>::Matrix(int r, int c) {
    rows = r;
    columns = c;
    cells = new T*[rows];
    for (int i = 0; i < r; i++)
        cells[i] = new T[columns]{};
}

/*
 * Конструктор класса Matrix
 * Скопировать содержимое одной матрицы
 */
template <class T>
Matrix<T>::Matrix(Matrix<T>& other) {
    this->rows = other.rows;
    this->columns = other.columns;

    cells = new T*[rows];
    for (int i = 0; i < rows; i++) {
        cells[i] = new T[columns];
        for (int j = 0; j < columns; j++)
            cells[i][j] = other.cells[i][j];
    }
}

/*
 * Деструктор класса Matrix
 * Удаление двумерного динамического массива cells
 */
template <class T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; i++)
        delete [] cells[i];
    delete [] cells;
}

/*
 * Инициализировать матрицу с клавиатуры
 */
template <class T>
void Matrix<T>::init() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            T x;
            cout << "At [" << i + 1 << "," << j + 1 << "]: ";
            cin >> x;
            cells[i][j] = x;
        }
    }
}

/*
 * Инициализировать матрицу из массива
 */
template <class T>
void Matrix<T>::init(T* arr) {
    unsigned c = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cells[i][j] = arr[c++];
}

/*
 * Размер X матрицы (строки
 */
template <class T>
unsigned Matrix<T>::getSizeX() {
    return rows;
}

/*
 * Размер Y матрицы
 */
template <class T>
unsigned Matrix<T>::getSizeY() {
    return columns;
}

/*
 * Получить элемент
 */
template <class T>
T Matrix<T>::get(unsigned x, unsigned y) {
    return cells[x][y];
}

/*
 * Транспонирование матрицы
 */
template <class T>
void Matrix<T>::transp() {
    for(int i = 0; i < rows; i++)
        for(int j = i; j < columns; j++)
            swap(cells[i][j], cells[j][i]);
}

/*
 * Перегрузка оператора вывода для Matrix
*/
template <class T>
ostream& operator<< (ostream& os, Matrix<T>& m) {
    os << "Matrix [" << m.rows << "x" << m.columns << "] = {" << endl;
    for (int i = 0; i < m.rows; i++) {
        os << '\t';
        for (int j = 0; j < m.columns; j++)
            os << setw (7) << m.cells[i][j] << " ";
        os << endl;
    }
    os << "}" << endl;
    return os;
}

/*
 * Перегрузка оператора вывода в QString для Matrix
*/
template <class T>
QString& operator<< (QString& qs, Matrix<T>& m) {
    qs += "{\n";
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.columns; j++) {
            qs += "\t";
            qs << m.cells[i][j];
        }
        qs += "\n";
    }
    qs += "}";
    return qs;
}

#endif // MATRIX_H
