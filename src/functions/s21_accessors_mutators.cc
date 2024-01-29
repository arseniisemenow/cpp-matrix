#include "../s21_matrix_oop.h"

namespace s21 {

void S21Matrix::ResizeMatrix(int new_rows, int new_cols) {
  CheckRowsAndColsUnderflow(new_rows, new_cols);
  if (rows_ == new_rows && cols_ == new_cols) {
    return;
  }

  S21Matrix temp = S21Matrix(new_rows, new_cols);

  for (int i = 0; i < temp.rows_ && i < rows_; ++i) {
    for (int j = 0; j < temp.cols_ && j < cols_; ++j) {
      temp(i, j) = matrix_[i][j];
    }
  }

  DestroyMatrix();

  rows_ = new_rows;
  cols_ = new_cols;

  AllocateMemoryForMatrix();
  CopyMatrixData(temp);
}

void S21Matrix::SetRows(int number) { ResizeMatrix(number, cols_); }

void S21Matrix::SetCols(int number) { ResizeMatrix(rows_, number); }

void S21Matrix::SetElementInMatrix(int number, int row_index, int col_index) {
  CheckRowAndColsFlows(row_index, col_index);
  matrix_[row_index][col_index] = number;
}

int S21Matrix::GetRows() const noexcept { return rows_; }

int S21Matrix::GetCols() const noexcept { return cols_; }

double S21Matrix::GetElementInMatrix(int row_index,
                                     int col_index) const noexcept {
  return matrix_[row_index][col_index];
}

}  // namespace s21