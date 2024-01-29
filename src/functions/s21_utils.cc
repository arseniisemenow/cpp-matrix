#include "../s21_matrix_oop.h"

namespace s21{

    [[nodiscard]] bool S21Matrix::IsFirstOrderMatrix() const{
        return (rows_ == 1 && cols_ == 1);
    }

    [[nodiscard]] bool S21Matrix::IsZero(const double value) {
        if (std::fabs(value) < 1e-7){
            return true;
        }
        return false;
    }
}