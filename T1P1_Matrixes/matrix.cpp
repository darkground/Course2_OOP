#include "matrix.h"
#include <iostream>

using namespace std;

matrix::matrix() {}

void matrix::print() {
    cout << "Matrix [" << MSIZE << "x" << MSIZE << "] = {" << endl;
    for (int i = 0; i < MSIZE; i++) {
        cout << '\t';
        for (int j = 0; j < MSIZE; j++) {
            cout << this->cells[i][j] << " ";
        }
        cout << endl;
    }
    cout << "}" << endl;
}

void matrix::init() {
    for (int i = 0; i < MSIZE; i++) {
        for (int j = 0; j < MSIZE; j++) {
            number x;
            cout << "At [" << i + 1 << "," << j + 1 << "]: ";
            cin >> x;
            this->cells[i][j] = x;
        }
    }
}

void matrix::transp() {
    for(int i = 0; i < MSIZE; ++i)
    {
        for(int j = i; j < MSIZE; ++j)
        {
            swap(this->cells[i][j], this->cells[j][i]);
        }
    }
}
