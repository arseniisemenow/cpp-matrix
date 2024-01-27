#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() const {
    //TODO handle errors
    S21Matrix transposedMatrix(cols_, rows_);

    for (int rowIndex = 0; rowIndex < rows_; ++rowIndex) {
        for (int colIndex = 0; colIndex < cols_; ++colIndex) {
            transposedMatrix.matrix_[colIndex][rowIndex] =
                    matrix_[rowIndex][colIndex];
        }
    }
    return transposedMatrix;
}