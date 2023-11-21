#include "matrix.h"
#include <iomanip>

using namespace std;

/*
 * Конструктор класса Matrix
 * Создать матрицу размера r x c
 */
Matrix::Matrix(int r, int c) {
    rows = r;
    columns = c;
    cells = new number*[rows];
    for (int i = 0; i < r; i++)
        cells[i] = new number[columns]{};
}

/*
 * Конструктор класса Matrix
 * Скопировать содержимое одной матрицы
 */
Matrix::Matrix(Matrix& other) {
    this->rows = other.rows;
    this->columns = other.columns;

    cells = new number*[rows];
    for (int i = 0; i < rows; i++) {
        cells[i] = new number[columns];
        for (int j = 0; j < columns; j++)
            cells[i][j] = other.cells[i][j];
    }
}

/*
 * Деструктор класса Matrix
 * Удаление двумерного динамического массива cells
 */
Matrix::~Matrix() {
    for (int i = 0; i < rows; i++)
        delete [] cells[i];
    delete [] cells;
}

/*
 * Инициализировать матрицу с клавиатуры
 */
void Matrix::init() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            number x;
            cout << "At [" << i + 1 << "," << j + 1 << "]: ";
            cin >> x;
            cells[i][j] = x;
        }
    }
}

/*
 * Инициализировать матрицу из массива
 */
void Matrix::init(number* arr) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cells[i][j] = arr[i * rows + j];
}

/*
 * Транспонирование матрицы
 */
void Matrix::transp() {
    for(int i = 0; i < rows; i++)
        for(int j = i; j < columns; j++)
            swap(cells[i][j], cells[j][i]);
}

/*
 * Перегрузка оператора вывода для Matrix
*/
ostream& operator<< (ostream& os, Matrix& m) {
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
QString& operator<< (QString& qs, Matrix& m) {
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
