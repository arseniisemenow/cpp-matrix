#include "../s21_matrix_oop.h"

void S21Matrix::CopyMatrixData(const S21Matrix& other) noexcept{
    cols_ = other.cols_;
    rows_ = other.rows_;

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            matrix_[i][j] = other(i, j);
        }
    }
}