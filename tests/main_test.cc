
#include "../src/s21_matrix_oop.h"
#include <iostream>

int main() {
    s21::S21Matrix matrix3x3(3,3);
    s21::S21Matrix matrix{};

    matrix3x3(0,0) = 1;
    matrix3x3(1,1) = 2;
    matrix3x3(2,2) = 3;

    matrix3x3.PrintMatrix();
    matrix = matrix3x3;
    matrix3x3.PrintMatrix();
}