#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../headers/s21_common.h"
#include "../s21_matrix_oop.h"
#include "s21_test.h"

#endif

START_TEST(eq_matrix_test1) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test2) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1.0;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test3) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 2, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test4) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 0.00000005;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test5) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  int code = s21_eq_matrix(&A, NULL);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(eq_matrix_test6) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test7) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(2, 1, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test8) {
  matrix_t B = {0};
  s21_create_matrix(1, 1, &B);
  int code = s21_eq_matrix(NULL, &B);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test9) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[1][1] = 2.0;
  B.matrix[1][1] = 3.0;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test10) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(3, 3, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test11) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, cols, &mtx);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      double rand_val = get_rand(DBL_MIN, DBL_MAX);
      m.matrix[i][j] = rand_val;
      mtx.matrix[i][j] = rand_val;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&m, &mtx), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

START_TEST(eq_matrix_test12) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, cols, &mtx);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&m, &mtx), FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

START_TEST(eq_matrix_test13) {
  const int rows1 = rand() % 100 + 1;
  const int cols1 = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows1, cols1, &m);
  const int rows2 = rand() % 100 + 1;
  const int cols2 = rand() % 100 + 1;
  matrix_t mtx = {0};
  s21_create_matrix(rows2, cols2, &mtx);

  for (int i = 0; i < rows1; ++i) {
    for (int j = 0; j < cols1; ++j) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
    }
  }
  for (int i = 0; i < rows2; ++i) {
    for (int j = 0; j < cols2; ++j) {
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&m, &mtx), FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

Suite *eq_matrix(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("eq_matrix");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, eq_matrix_test1);
  tcase_add_test(tc_core, eq_matrix_test2);
  tcase_add_test(tc_core, eq_matrix_test3);
  tcase_add_test(tc_core, eq_matrix_test4);
  tcase_add_test(tc_core, eq_matrix_test5);
  tcase_add_test(tc_core, eq_matrix_test6);
  tcase_add_test(tc_core, eq_matrix_test7);
  tcase_add_test(tc_core, eq_matrix_test8);
  tcase_add_test(tc_core, eq_matrix_test9);
  tcase_add_test(tc_core, eq_matrix_test10);
  tcase_add_test(tc_core, eq_matrix_test11);
  tcase_add_test(tc_core, eq_matrix_test12);
  tcase_add_test(tc_core, eq_matrix_test13);
  suite_add_tcase(s, tc_core);
  return s;
}
