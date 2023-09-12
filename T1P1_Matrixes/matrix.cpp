#include "matrix.h"
#include <iostream>
#include <math.h>

using namespace std;

matrix::matrix() {}

void matrix::print() {
    cout << "Matrix [" << MSIZE << "x" << MSIZE << "] = {" << endl;
    for (int i = 0; i < MSIZE; i++) {
        cout << '\t';
        for (int j = 0; j < MSIZE; j++)
            cout << this->cells[i][j] << " ";
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
    for(int i = 0; i < MSIZE; i++)
        for(int j = i; j < MSIZE; j++)
            swap(this->cells[i][j], this->cells[j][i]);
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

//    if(determ == -0) {
//        determ = 0;
//    }

    cout << "Determinant: " << determ << endl;
}
