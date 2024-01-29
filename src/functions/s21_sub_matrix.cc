#include "../s21_matrix_oop.h"

namespace s21 {
void S21Matrix::SubMatrix(const S21Matrix &other) {
  CheckMatricesSizeIdentity(other);
  PerformSumAndSubOperations(other, OperationType::kSubtraction);
}
}  // namespace s21