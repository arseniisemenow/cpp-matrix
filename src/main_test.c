
#include "develop/s21_develop.h"
#include "s21_matrix_oop.h"

int main() {
  matrix_t inputMatrix = {0}, resultMatrix = {0};
  int size = 5;
  s21_create_matrix(size, size, &inputMatrix);

    inputMatrix.matrix[0][1] = 6;
    inputMatrix.matrix[0][2] = -2;
    inputMatrix.matrix[0][3] = -1;
    inputMatrix.matrix[0][4] = 5;
    inputMatrix.matrix[1][3] = -9;
    inputMatrix.matrix[1][4] = -7;
    inputMatrix.matrix[2][1] = 15;
    inputMatrix.matrix[2][2] = 35;
    inputMatrix.matrix[3][1] = -1;
    inputMatrix.matrix[3][2] = -11;
    inputMatrix.matrix[3][3] = -2;
    inputMatrix.matrix[3][4] = 1;
    inputMatrix.matrix[4][0] = -2;
    inputMatrix.matrix[4][1] = -2;
    inputMatrix.matrix[4][2] = 3;
    inputMatrix.matrix[4][4] = -2;

    printMatrixFile(&inputMatrix);
double result = 0;
  int returnValue = s21_determinant(&inputMatrix, &result);
  printf("returnValue: %d, result: %lf\n", returnValue, result);
  s21_remove_matrix(&inputMatrix);
}