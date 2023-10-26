#include "matrix.h"
#include <iomanip>

using namespace std;

/*
 * Конструктор класса matrix
 * Создать матрицу размера s
 */
matrix::matrix(int s) {
    size = s;
    cells = new number*[size];
    for (int i = 0; i < size; i++)
        cells[i] = new number[size]{};
}

/*
 * Конструктор класса matrix
 * Скопировать содержимое одной матрицы
 */
matrix::matrix(matrix& other) {
    this->size = other.size;
    cells = new number*[size];
    for (int i = 0; i < size; i++) {
        cells[i] = new number[size];
        for (int j = 0; j < size; j++)
            cells[i][j] = other.cells[i][j];
    }
}

/*
 * Деструктор класса matrix
 * Удаление двумерного динамического массива cells
 */
matrix::~matrix() {
    for (int i = 0; i < size; i++)
        delete [] cells[i];
    delete [] cells;
}

/*
 * Инициализировать матрицу с клавиатуры
 */
void matrix::init() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
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
void matrix::init(number* arr, int s) {
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            cells[i][j] = arr[i * s + j];
}

/*
 * Транспонирование матрицы
 */
void matrix::transp() {
    for(int i = 0; i < size; i++)
        for(int j = i; j < size; j++)
            swap(cells[i][j], cells[j][i]);
}

/*
 * Вычисление определителя через алгебраические дополнения
 * и миноры
 */
number matrix::determ() {
    if (size == 1)
        return cells[0][0];
    else if (size == 2)
        return cells[0][0] * cells[1][1] - cells[0][1] * cells[1][0];

    number det = 0;
    for (int k = 0; k < size; k++) {
        matrix m(size - 1);
        for (int i = 1; i < size; i++) {
            int t = 0;
            for (int j = 0; j < size; j++) {
                if (j == k)
                    continue;
                m.cells[i-1][t] = cells[i][j];
                t++;
            }
        }
        det += number(pow(-1, k + 2)) * cells[0][k] * m.determ();
    }
    return det;
}

/*
 * Вычисление ранга матрицы через Метод Гаусса
 */
int matrix::rank()
{
    int rank = size;

    matrix copy(*this);

    for (int row = 0; row < rank; row++) {
        if (copy.cells[row][row] != 0) {
            for (int col = 0; col < size; col++) {
                if (col != row) {
                    number mult = copy.cells[col][row] / copy.cells[row][row];
                    for (int i = 0; i < rank; i++)
                        copy.cells[col][i] -= mult * copy.cells[row][i];
                }
            }
        } else {
            bool onlyZeros = true;
            for (int i = row + 1; i < size;  i++) {
                if (copy.cells[i][row] != 0) {
                    for (int j = 0; j < rank; j++)
                        swap(copy.cells[row][j], copy.cells[i][j]);
                    onlyZeros = false;
                    break;
                }
            }
            if (onlyZeros) {
                rank--;
                for (int i = 0; i < size; i ++)
                    copy.cells[i][row] = copy.cells[i][rank];
            }
            row--;
        }
    }
    return rank;
}

/*
 * Перегрузка оператора вывода для matrix
*/
ostream& operator<< (ostream& os, matrix& m) {
    os << "Matrix [" << m.size << "x" << m.size << "] = {" << endl;
    for (int i = 0; i < m.size; i++) {
        os << '\t';
        for (int j = 0; j < m.size; j++)
            os << setw (7) << m.cells[i][j] << " ";
        os << endl;
    }
    os << "}" << endl;
    return os;
}

/*
 * Перегрузка оператора вывода в QString для matrix
*/
QString& operator<< (QString& qs, matrix& m) {
    qs += "{\n";
    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            qs += "\t";
            qs << m.cells[i][j];
        }
        qs += "\n";
    }
    qs += "}";
    return qs;
}
