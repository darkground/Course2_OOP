#include "matrix.h"

using namespace std;

matrix::matrix(int s) {
    size = s;
    cells = new number*[size];
    for (int i = 0; i < size; i++)
        cells[i] = new number[size]{};
}

matrix::matrix(matrix& other) {
    this->size = other.size;
    cells = new number*[size];
    for (int i = 0; i < size; i++) {
        cells[i] = new number[size];
        for (int j = 0; j < size; j++)
            cells[i][j] = other.cells[i][j];
    }
}

matrix::~matrix() {
    for (int i = 0; i < size; i++)
        delete [] cells[i];
    delete [] cells;
}

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
        det += pow(-1, k + 2) * cells[0][k] * m.determ();
    }
    return det;
}

int matrix::rank()
{
    int rank = size;

    matrix copy(*this);

    for (int row = 0; row < rank; row++) {
        if (copy.cells[row][row] != 0) {
            for (int col = 0; col < size; col++) {
                if (col != row) {
                    double mult = (double)copy.cells[col][row] / copy.cells[row][row];
                    for (int i = 0; i < rank; i++)
                        copy.cells[col][i] -= mult * copy.cells[row][i];
                }
            }
        } else {
            bool onlyZeros = true;
            for (int i = row + 1; i < size;  i++) {
                if (copy.cells[i][row] != 0) {
                    for (int j = 0; j < rank; j++)
                        swap(cells[row][j], cells[i][j]);
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

ostream& operator<< (ostream& os, matrix& m) {
    os << "Matrix [" << m.size << "x" << m.size << "] = {" << endl;
    for (int i = 0; i < m.size; i++) {
        os << '\t';
        for (int j = 0; j < m.size; j++)
            os << m.cells[i][j] << " ";
        os << endl;
    }
    os << "}" << endl;
    return os;
}

void matrix::determ() {
    number matrix2[MSIZE][MSIZE];

    for(int i = 0; i < MSIZE; i++) {
        for(int j = 0; j < MSIZE; j++) {
            matrix2[i][j] = this->cells[i][j];
        }
    }

    for (int i = 0; i < MSIZE; ++i) {
        for(int j = 0; j < MSIZE; j++) {
            cout << matrix2[i][j];
        }
        cout << endl;
    }
    cout << endl;

    number x =0;
    for(int f = 0, k = 0; f < MSIZE - 1; f++, k++) {
        for(int i = f + 1; i < MSIZE; i++) {
            x  = matrix2[i][k] / matrix2[f][k];
            for(int j = k; j < MSIZE; j++) {
                matrix2[i][j] -= matrix2[f][j] * x;
            }
        }
    }

    number determ = 1;
    for(int i = 0; i < MSIZE; i++) {
        determ *= matrix2[i][i];
    }

    cout << "Determinant: " << determ << endl;
}

ostream& operator<< (ostream& os, matrix& m) {
    os << "Matrix [" << MSIZE << "x" << MSIZE << "] = {" << endl;
    for (int i = 0; i < MSIZE; i++) {
        os << '\t';
        for (int j = 0; j < MSIZE; j++)
            os << m.cells[i][j] << " ";
        os << endl;
    }
    os << "}" << endl;
    return os;
}
