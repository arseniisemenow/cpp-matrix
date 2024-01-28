
#include "../src/s21_matrix_oop.h"
//#include "tests.h"
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
    s21::S21Matrix matrix3x3{3,3};


    matrix3x3(0, 0) = 1;
    matrix3x3(0, 1) = 2;
    matrix3x3(0, 2) = 3;

    matrix3x3(1, 0) = 4;
    matrix3x3(1, 1) = 5;
    matrix3x3(1, 2) = 6;

    matrix3x3(2, 0) = 7;
    matrix3x3(2, 1) = 8;
    matrix3x3(2, 2) = 9;

    matrix3x3(0, 0) = 1;
    matrix3x3(0, 1) = 2;
    matrix3x3(0, 2) = 3;

    matrix3x3(1, 0) = 4;
    matrix3x3(1, 1) = 5;
    matrix3x3(1, 2) = 6;

    matrix3x3(2, 0) = 7;
    matrix3x3(2, 1) = 8;
    matrix3x3(2, 2) = 9;


    matrix3x3.SumMatrix(matrix3x3);
    s21::S21Matrix result{ 3, 3 };
    result(0, 0) = 2;
    result(0, 1) = 4;
    result(0, 2) = 6;

    result(1, 0) = 8;
    result(1, 1) = 10;
    result(1, 2) = 12;

    result(2, 0) = 14;
    result(2, 1) = 16;
    result(2, 2) = 18;

//    ASSERT_EQ(result, matrix3x3);
    matrix3x3.PrintMatrix();
    result.PrintMatrix();

//    EXPECT_THROW(matrix3x3.SumMatrix(matrix2x2), std::invalid_argument);

}