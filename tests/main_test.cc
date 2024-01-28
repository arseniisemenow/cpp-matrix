
#include "s21_matrix_oop.h"
#include <iostream>

void RandomizeMatrix(S21Matrix& matrix) {
    // Get the number of rows and columns in the matrix
    int rows = matrix.GetRows();
    int cols = matrix.GetCols();

    // Generate random values for each element in the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix(i, j) = rand() % 10;
        }
    }
}

int main() {

    srand(time(NULL));

    int size = 80;
    S21Matrix matrix1(size, size);

    RandomizeMatrix(matrix1);

    // Initialize the matrix with values
//    for (int i = 0; i <size; i++) {
//        for (int j = 0; j <size; j++) {
//            matrix1(i, j) = (i + j) % 2 == 0 ? i * 5 + j : i * (9 + i  *j / 3 * 14);
//        }
//    }
//    matrix1(0,0) = 15;


    matrix1.PrintMatrix();

    std::cout << "Det: " << matrix1.Determinant() << std::endl;

    double result = 0;
}