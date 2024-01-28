#include "../s21_matrix_oop.h"

namespace s21{
    void S21Matrix::SumMatrix(const S21Matrix &other) {
        CheckMatricesSizeIdentity(other);
        PerformSumAndSubOperations(other, OperationType::kAddition);
    }
}