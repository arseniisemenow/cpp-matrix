
#include <iostream>

#include "../src/s21_matrix_oop.h"

int main() {
  s21::S21Matrix matrix1x1(1, 1);

  matrix1x1(0, 0) = 15;

  s21::S21Matrix complements{matrix1x1.CalcComplements()};

  complements.PrintMatrix();
}