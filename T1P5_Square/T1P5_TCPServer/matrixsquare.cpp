#include "matrixsquare.h"

MatrixSquare::MatrixSquare(int s) : Matrix(s, s) {
    size = s;
}

/*
 * Вычисление определителя через алгебраические дополнения
 * и миноры
 */
number MatrixSquare::determ() {
    if (size == 1)
        return cells[0][0];
    else if (size == 2)
        return cells[0][0] * cells[1][1] - cells[0][1] * cells[1][0];

    number det = 0;
    for (int k = 0; k < size; k++) {
        MatrixSquare m(size - 1);
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
int MatrixSquare::rank() {
    int rank = size;

    MatrixSquare copy(*this);

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
                    for (int j = 0; j < rank; j++) {
                        number t = copy.cells[row][j];
                        copy.cells[row][j] = copy.cells[i][j];
                        copy.cells[i][j] = t;
                    }
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
