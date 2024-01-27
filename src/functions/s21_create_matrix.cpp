#include "../s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept {
    InitNullMatrix();
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
    if (rows < 0 || cols < 0) {
        InitNullMatrix();
    } else {
        AllocateMemoryForMatrix(rows_, cols_);
    }
}

void S21Matrix::AllocateMemoryForMatrix(int rows, int cols) noexcept {
    rows_ = rows;
    cols_ = cols;
    matrix_ = new double *[rows_];

    for (int i = 0; i < rows_; ++i) {
        matrix_[i] = new double[cols_]();
    }
}

void S21Matrix::InitNullMatrix() noexcept {
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
}

S21Matrix::S21Matrix(const S21Matrix &other) {
    AllocateMemoryForMatrix(other.rows_, other.cols_);
    CopyMatrixData(other);
}

S21Matrix::S21Matrix(S21Matrix && other) noexcept
{
    InitNullMatrix();
    std::swap(other.rows_, rows_);
    std::swap(other.cols_, cols_);
    std::swap(other.matrix_, matrix_);
}