
#include "../src/s21_matrix_oop.h"
#include <iostream>

void RandomizeMatrix(s21::S21Matrix& matrix) {
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

    int size = 1000;
    s21::S21Matrix matrix1(size, size);

    RandomizeMatrix(matrix1);

    std::cout << "Det: " << matrix1.Determinant() << std::endl;

    double result = 0;
}