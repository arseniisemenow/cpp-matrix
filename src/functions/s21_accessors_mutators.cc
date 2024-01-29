#include "../s21_matrix_oop.h"

namespace s21 {

void S21Matrix::ResizeMatrix(int newRows, int newCols) {
  CheckRowsAndColsUnderflow(newRows, newCols);
  if (rows_ == newRows && cols_ == newCols) {
    return;
  }

  S21Matrix temp = S21Matrix(newRows, newCols);

  for (int i = 0; i < temp.rows_ && i < rows_; ++i) {
    for (int j = 0; j < temp.cols_ && j < cols_; ++j) {
      temp(i, j) = matrix_[i][j];
    }
  }

  DestroyMatrix();

  rows_ = newRows;
  cols_ = newCols;

  AllocateMemoryForMatrix();
  CopyMatrixData(temp);
}

void S21Matrix::SetRows(int number) { ResizeMatrix(number, cols_); }

void S21Matrix::SetCols(int number) { ResizeMatrix(rows_, number); }

void S21Matrix::SetElementInMatrix(int number, int rowIndex, int colIndex) {
  CheckRowAndColsFlows(rowIndex, colIndex);
  matrix_[rowIndex][colIndex] = number;
}

int S21Matrix::GetRows() const noexcept { return rows_; }

int S21Matrix::GetCols() const noexcept { return cols_; }

double S21Matrix::GetElementInMatrix(int rowIndex,
                                     int colIndex) const noexcept {
  return matrix_[rowIndex][colIndex];
}

}  // namespace s21