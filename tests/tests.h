#ifndef S21_MATRIX_TESTS_H
#define S21_MATRIX_TESTS_H

#include <gtest/gtest.h>
#include "../src/s21_matrix_oop.h"

namespace s21
{
class S21MatrixTest : public ::testing::Test
{
protected:
    void SetUp() override;

    s21::S21Matrix matrix1x1{ 1, 1 };
    s21::S21Matrix matrix2x2{ 2, 2 };
    s21::S21Matrix matrix2x3{ 2, 3 };
    s21::S21Matrix matrix3x3{ 3, 3 };

private:
    void SetUp2x2Matrix();
    void SetUp2x3Matrix();
    void SetUp3x3Matrix();
};
}

#endif
