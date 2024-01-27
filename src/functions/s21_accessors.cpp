#include "../s21_matrix_oop.h"

void S21Matrix::ResizeMatrix(int newRows, int newCols) {
    if (newRows < 0 || newCols < 0) {
        throw std::length_error("Number of rows or columns can't be negative.\n");
    }

    if (rows_ != newRows || cols_ != newCols) {
        S21Matrix temp = S21Matrix(newRows, newCols);

        for (int i = 0; i < temp.rows_; ++i) {
            for (int j = 0; j < temp.cols_; ++j) {
                if (i < rows_ && j < cols_) {
                    temp(i, j) = matrix_[i][j];
                }
            }
        }

        DestroyMatrix();

        AllocateMemoryForMatrix(temp.rows_, temp.cols_);
        CopyMatrixData(temp);
    }
}

void S21Matrix::SetRows(int number) {
    ResizeMatrix(number, cols_);
}

void S21Matrix::SetCols(int number) {
    ResizeMatrix(rows_, number);
}

void S21Matrix::SetElementInMatrix(int number, int rowIndex, int colIndex) {
    if (rowIndex < 0 || colIndex < 0){
        throw std::length_error("The index of row and column can't be negative number");
    }
    matrix_[rowIndex][colIndex] = number;
}

int S21Matrix::GetRows() const noexcept {
    return rows_;
}
int S21Matrix::GetCols() const noexcept {
    return cols_;
}

double S21Matrix::GetElementInMatrix(int rowIndex, int colIndex) const noexcept {
    return matrix_[rowIndex][colIndex];
}