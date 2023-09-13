#include "application.h"
#include <iostream>

using namespace std;

TApplication::TApplication() {}

int TApplication::exec() {
    int s;
    cout << "Enter matrix size: ";
    cin >> s;
    matr = new matrix(s);
    while (true) {
        int choice = menu();

        switch(choice) {
            case 1:
                matr->init();
                break;
            case 2:
                cout << "Determinant: " << matr->determ() << endl;
                break;
            case 3:
                matr->transp();
                cout << *matr;
                break;
            case 4:
                break;
            case 5:
                cout << *matr;
                break;
            case 0:
                return 0;
            default:
                break;
        }
    }
    delete matr;
}

int TApplication::menu() {
    int user_choice;
    /*
     * 1. Ввод матрицы с клавиатуры
     * 2. Определитель матрицы
     * 3. Транспонирование матрицы
     * 4. Вычислить ранг матрицы
     * 5. Печать матрицы в консоль
     */
    cout
        << endl << endl
        << "Matrix Menu" << endl
        << "1) Initialize from keyboard" << endl
        << "2) Calculate determinant of current matrix" << endl
        << "3) Transpose current matrix" << endl
        << "4) Calculate rank of current matrix" << endl
        << "5) Print current matrix representation" << endl
        << "0) Exit application" << endl;
    cin >> user_choice;
    return user_choice;
}
