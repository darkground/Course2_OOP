#include "matrix.h"
#include <iostream>

using namespace std;

matrix::matrix() {}

void matrix::print() {
    cout << "Matrix [" << MSIZE << "x" << MSIZE << "] = {" << endl;
    for (int i = 0; i < MSIZE; i++) {
        cout << '\t';
        for (int j = 0; j < MSIZE; j++) {
            cout << this->cells[i * 3 + j] << " ";
        }
        cout << endl;
    }
    cout << "}" << endl;
}

void matrix::init() {
    for (int i = 0; i < MSIZE * MSIZE; i++) {
        number x;
        cout << "At [" << i / 3 + 1 << "," << i % 3 + 1 << "]: ";
        cin >> x;
        this->cells[i] = x;
    }
}
