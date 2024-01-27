#include "../s21_matrix_oop.h"

S21Matrix &S21Matrix::operator=(const S21Matrix &other){
    if (*this == other){
        return *this;
    }
    DestroyMatrix();

    rows_ = other.rows_;
    cols_ = other.cols_;
    AllocateMemoryForMatrix(rows_, cols_);
    CopyMatrixData(other);
}

bool S21Matrix::operator==(const S21Matrix &other) const{
    return EqMatrix(other);
}

S21Matrix S21Matrix::operator*(const S21Matrix &other){
    S21Matrix temp = *this;
    temp.MulMatrix(other);
    return temp;
}