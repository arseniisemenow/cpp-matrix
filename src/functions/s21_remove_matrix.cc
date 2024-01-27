#include "../s21_matrix_oop.h"

S21Matrix::~S21Matrix() {
    DestroyMatrix();
    rows_ = 0;
    cols_ = 0;
}

void S21Matrix::DestroyMatrix(){
    if (matrix_ != nullptr){
        for (int i = 0; i < rows_; ++i) {
            if (matrix_[i] != nullptr){
                delete[] matrix_[i];
                matrix_[i] = nullptr;
            }
        }
        delete matrix_;
        matrix_ = nullptr;
    }
}