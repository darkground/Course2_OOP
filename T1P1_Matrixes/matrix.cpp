#include "matrix.h"

using namespace std;

matrix::matrix(int s) {
    size = s;
    cells = new number*[size];
    for (int i = 0; i < size; i++)
        cells[i] = new number[size]{};
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

number matrix::determ() {
    if (this->size == 1)
        return cells[0][0];
    else if (this->size == 2)
        return cells[0][0] * cells[1][1] - cells[0][1] * cells[1][0];
    number d = 0;
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
        d += pow(-1, k + 2) * cells[0][k] * m.determ();
    }
    return d;
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
