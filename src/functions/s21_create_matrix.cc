#include "../s21_matrix_oop.h"
namespace s21{

    S21Matrix::S21Matrix() {
        rows_ = 0;
        cols_ = 0;
        matrix_ = nullptr;
    }
    S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
        if (rows < 0 || cols < 0) {
            throw std::invalid_argument("Invalid arguments for constructor");
        } else {
            AllocateMemoryForMatrix();
        }
    }

    S21Matrix::S21Matrix(const S21Matrix& other): rows_(other.rows_), cols_(other.cols_) {
        AllocateMemoryForMatrix();
        CopyMatrixData(other);
    }

    void S21Matrix::AllocateMemoryForMatrix() {
        matrix_ = new double *[rows_];

        for (int i = 0; i < rows_; ++i) {
            matrix_[i] = new double[cols_]();
        }
    }
}
