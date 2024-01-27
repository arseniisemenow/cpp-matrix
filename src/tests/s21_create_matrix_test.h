#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../headers/s21_common.h"
#include "../s21_matrix_oop.h"
#include "s21_test.h"

#endif

START_TEST(create_matrix_test1) {
  matrix_t m = {0};
  int code = s21_create_matrix(3, 3, &m);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&m);
}

END_TEST

START_TEST(create_matrix_test2) {
  matrix_t m = {0};
  int code = s21_create_matrix(1, 1, &m);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&m);
}

END_TEST

START_TEST(create_matrix_test3) {
  matrix_t m = {0};
  int code = s21_create_matrix(2, 3, &m);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&m);
}

END_TEST

START_TEST(create_matrix_test4) {
  matrix_t m = {0};
  int code = s21_create_matrix(1000, 1000, &m);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&m);
}

END_TEST

START_TEST(create_matrix_test5) {
  matrix_t m = {0};
  int code = s21_create_matrix(0, 3, &m);
  ck_assert_int_eq(code, 1);
}

END_TEST

START_TEST(create_matrix_test6) {
  matrix_t m = {0};
  int code = s21_create_matrix(3, 0, &m);
  ck_assert_int_eq(code, 1);
}

END_TEST

START_TEST(create_matrix_test7) {
  matrix_t m = {0};
  int code = s21_create_matrix(-3, 3, &m);
  ck_assert_int_eq(code, 1);
}

END_TEST

START_TEST(create_matrix_test8) {
  matrix_t m = {0};
  int code = s21_create_matrix(3, -3, &m);
  ck_assert_int_eq(code, 1);
}

END_TEST

START_TEST(create_matrix_test9) {
  matrix_t m = {0};
  int code = s21_create_matrix(0, 0, &m);
  ck_assert_int_eq(code, 1);
}

END_TEST

START_TEST(create_matrix_test10) {
  int code = s21_create_matrix(3, 3, NULL);
  ck_assert_int_eq(code, 1);
}

END_TEST

START_TEST(create_matrix_test11) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      m.matrix[i][j] = 0;
      ck_assert_ldouble_eq_tol(0, m.matrix[i][j], 1e-07);
    }
  }
  ck_assert_int_eq(m.rows, rows);
  ck_assert_int_eq(m.columns, cols);
  s21_remove_matrix(&m);
}

END_TEST

START_TEST(create_matrix_test12) {
  int rows = 10;
  int columns = 10;
  matrix_t matrix = {0};
  int status1 = s21_create_matrix(rows, columns, &matrix);

  if (matrix.matrix) {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        ck_assert(fabs(matrix.matrix[i][j]) < 1e-7);
      }
    }
    ck_assert_int_eq(matrix.rows, rows);
    ck_assert_int_eq(matrix.columns, columns);
    ck_assert_int_eq(status1, returnValue_Ok);
  } else {
    ck_assert_int_eq(status1, returnValue_CalculationError);
  }

  if (status1 == returnValue_Ok) s21_remove_matrix(&matrix);
}

END_TEST

START_TEST(create_matrix_test13) {
  const int rows = 0;
  const int cols = 10;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m),
                   returnValue_IncorrectMatrixError);
}

END_TEST

START_TEST(create_matrix_test14) {
  const int rows = 10;
  const int cols = 0;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m),
                   returnValue_IncorrectMatrixError);
}

END_TEST

START_TEST(create_matrix_test15) {
  int rows = -10;
  int columns = 10;
  matrix_t matrix = {0};
  int status = s21_create_matrix(rows, columns, &matrix);

  ck_assert_int_eq(status, returnValue_IncorrectMatrixError);

  if (status == returnValue_Ok) s21_remove_matrix(&matrix);
}

END_TEST

Suite *create_matrix(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("create_matrix");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, create_matrix_test1);
  tcase_add_test(tc_core, create_matrix_test2);
  tcase_add_test(tc_core, create_matrix_test3);
  tcase_add_test(tc_core, create_matrix_test4);
  tcase_add_test(tc_core, create_matrix_test5);
  tcase_add_test(tc_core, create_matrix_test6);
  tcase_add_test(tc_core, create_matrix_test7);
  tcase_add_test(tc_core, create_matrix_test8);
  tcase_add_test(tc_core, create_matrix_test9);
  tcase_add_test(tc_core, create_matrix_test10);
  tcase_add_test(tc_core, create_matrix_test11);
  tcase_add_test(tc_core, create_matrix_test12);
  tcase_add_test(tc_core, create_matrix_test13);
  tcase_add_test(tc_core, create_matrix_test14);
  tcase_add_test(tc_core, create_matrix_test15);
  suite_add_tcase(s, tc_core);
  return s;
}
