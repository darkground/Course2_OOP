#include "matrix.h"

using namespace std;

matrix::matrix(int size) {
    this->size = size;
    this->cells = new number*[this->size];
    for (int i = 0; i < this->size; i++)
        this->cells[i] = new number[this->size]{};
}

matrix::~matrix() {
    for (int i = 0; i < this->size; i++)
        delete [] this->cells[i];
    delete [] this->cells;
}

void matrix::init() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            number x;
            cout << "At [" << i + 1 << "," << j + 1 << "]: ";
            cin >> x;
            this->cells[i][j] = x;
        }
    }
}

void matrix::transp() {
    for(int i = 0; i < this->size; i++)
        for(int j = i; j < this->size; j++)
            swap(this->cells[i][j], this->cells[j][i]);
}

number matrix::determ() {
    if (this->size == 1)
        return this->cells[0][0];
    else if (this->size == 2)
        return this->cells[0][0] * this->cells[1][1] - this->cells[0][1] * this->cells[1][0];
    number d = 0;
    for (int k = 0; k < this->size; k++) {
        matrix m(this->size - 1);
        for (int i = 1; i < this->size; i++) {
            int t = 0;
            for (int j = 0; j < this->size; j++) {
                if (j == k)
                    continue;
                m.cells[i-1][t] = this->cells[i][j];
                t++;
            }
        }
        d += pow(-1, k + 2) * this->cells[0][k] * m.determ();
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
