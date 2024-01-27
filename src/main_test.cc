
#include "s21_matrix_oop.h"

int main() {
    S21Matrix matrix1(1, 2);
    S21Matrix matrix2(1, 2);

    matrix1(0, 0) = 1;
    matrix1(0, 1) = 5;

    matrix2(0, 0) = 123;
    matrix2(0, 1) = 3;

    matrix1.SumMatrix(matrix2);

    matrix1.PrintMatrix();

    double result = 0;
}