#include "../s21_matrix_oop.h"


namespace s21{
void S21Matrix::MulMatrix(const S21Matrix &other){
    if (cols_ != other.rows_){
        throw std::invalid_argument("The multiplication can't be completed");
    }
    PerformMatricesMulOperation(other);
}

void S21Matrix::PerformMatricesMulOperation(const S21Matrix& other) {
    S21Matrix temp = S21Matrix(rows_, other.cols_);

  for (int rowIndex = 0; rowIndex < rows_; ++rowIndex) {
    for (int otherCols = 0; otherCols < other.cols_; ++otherCols) {
        temp.matrix_[rowIndex][otherCols] = 0;
      for (int colIndex = 0; colIndex < cols_; ++colIndex) {
        temp.matrix_[rowIndex][otherCols] +=
                matrix_[rowIndex][colIndex] *
                other.matrix_[colIndex][otherCols];
      }
    }
  }
  *this = temp;
}}