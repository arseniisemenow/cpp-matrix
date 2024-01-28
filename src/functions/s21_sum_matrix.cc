#include "../s21_matrix_oop.h"

namespace s21{

    void S21Matrix::SumMatrix(const S21Matrix &other) {
        if (rows_ != other.rows_ || cols_ != other.cols_){
            throw std::invalid_argument("Non compatible rows or cols for sum operation");
        }
        PerformSumAndSubOperations(other, OperationType::kAddition);
    }
}