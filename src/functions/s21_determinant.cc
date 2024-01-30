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
    temp_result *= temp(pivot_index, pivot_index);
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
    double pivot_number = temp(pivot_index, pivot_index);
    double row_number = temp(row_index, pivot_index);

    if (std::fabs(pivot_number) < std::fabs(row_number)) {
      SwapRows(temp, pivot_index, row_index);
      (*p_swap_count)++;
    }
  }
}

void S21Matrix::PerformGaussElimination(S21Matrix &temp,
                                        int pivot_index) const {
  for (int rowIndex = pivot_index + 1; rowIndex < rows_; ++rowIndex) {
    double rowNumber = temp(rowIndex, pivot_index);
    double pivotNumber = temp(pivot_index, pivot_index);
    double term = rowNumber / pivotNumber;

    for (int colIndex = 0; colIndex < rows_; colIndex++) {
      double colNumber = temp(pivot_index, colIndex);
      double newColNumber = term * colNumber;
      temp(rowIndex, colIndex) -= newColNumber;
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
  for (int col_index = 0; col_index < temp.rows_; col_index++) {
    double &secondNumber = temp(row_index_2, col_index);
    double &firstNumber = temp(row_index_1, col_index);
    std::swap(firstNumber, secondNumber);
  }
}

double S21Matrix::GetSignBySwapCount(int swapCount) const {
  double result = 1.0;
  bool is_odd_number = swapCount % 2 == 1;
  if (is_odd_number) {
    result = -1.0;
  }
  return result;
}
}  // namespace s21