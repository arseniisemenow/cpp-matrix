#include "../s21_matrix_oop.h"

namespace s21 {

double S21Matrix::Determinant() const {
  CheckEmptyMatrix(*this);
  CheckSquareMatrix();

  S21Matrix temp = *this;
  double result = 0;

  int swap_count = GaussElimination(temp);

  double temp_result = 1;

  for (int pivot_index = 0; pivot_index < rows_; ++pivot_index) {
    temp_result *= temp.matrix_[pivot_index][pivot_index];
  }

  double sign = GetSignBySwapCount(swap_count);

  if (!std::isnan(temp_result)) {
    result = sign * temp_result;
  }
  if (IsZero(temp_result)) {
    result = 0;
  }

  return result;
}

void S21Matrix::PartialPivotingInGaussElimination(S21Matrix &temp,
                                                  int pivot_index,
                                                  int *p_swap_count) const {
  for (int row_index = pivot_index + 1; row_index < temp.rows_; row_index++) {
    double pivot_number = temp.matrix_[pivot_index][pivot_index];
    double row_number = temp.matrix_[row_index][pivot_index];

    if (std::fabs(pivot_number) < std::fabs(row_number)) {
      SwapRows(temp, pivot_index, row_index);
      (*p_swap_count)++;
    }
  }
}

void S21Matrix::PerformGaussElimination(S21Matrix &temp,
                                        int pivot_index) const {
  for (int rowIndex = pivot_index + 1; rowIndex < rows_; ++rowIndex) {
    double rowNumber = temp.matrix_[rowIndex][pivot_index];
    double pivotNumber = temp.matrix_[pivot_index][pivot_index];
    double term = rowNumber / pivotNumber;
    for (int colIndex = 0; colIndex < rows_; colIndex++) {
      double colNumber = temp.matrix_[pivot_index][colIndex];
      double newColNumber = term * colNumber;
      temp.matrix_[rowIndex][colIndex] -= newColNumber;
    }
  }
}

int S21Matrix::GaussElimination(S21Matrix &temp) const {
  int swap_count = 0;
  for (int pivot_index = 0; pivot_index < temp.rows_ - 1; pivot_index++) {
    PartialPivotingInGaussElimination(temp, pivot_index, &swap_count);
    PerformGaussElimination(temp, pivot_index);
  }
  return swap_count;
}

void S21Matrix::SwapRows(S21Matrix &temp, int row_index_1,
                         int row_index_2) const {
  for (int columnIndex = 0; columnIndex < temp.rows_; columnIndex++) {
    double tempValue = temp.matrix_[row_index_1][columnIndex];
    temp.matrix_[row_index_1][columnIndex] =
        temp.matrix_[row_index_2][columnIndex];
    temp.matrix_[row_index_2][columnIndex] = tempValue;
  }
}

double S21Matrix::GetSignBySwapCount(int swapCount) const {
  return swapCount % 2 == 1 ? -1.0 : 1.0;
}
}  // namespace s21