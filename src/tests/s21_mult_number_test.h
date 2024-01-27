#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../headers/s21_common.h"
#include "../s21_matrix_oop.h"
#include "s21_test.h"

#endif

START_TEST(mult_number_test1) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 1.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 1.0;
  double number = 0.5;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 0.5;
  B.matrix[0][1] = 0.5;
  B.matrix[1][0] = 0.5;
  B.matrix[1][1] = 0.5;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), 0);
  ck_assert(s21_eq_matrix(&B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test2) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1000000.0;
  A.matrix[0][1] = 1000000.0;
  A.matrix[1][0] = 1000000.0;
  A.matrix[1][1] = 1000000.0;
  double number = 1000000.0;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1000000000000.0;
  B.matrix[0][1] = 1000000000000.0;
  B.matrix[1][0] = 1000000000000.0;
  B.matrix[1][1] = 1000000000000.0;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), 0);
  ck_assert(s21_eq_matrix(&B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test3) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 0.0000001;
  A.matrix[0][1] = 0.0000001;
  A.matrix[1][0] = 0.0000001;
  A.matrix[1][1] = 0.0000001;
  double number = 0.0000001;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 0.00000000000001;
  B.matrix[0][1] = 0.00000000000001;
  B.matrix[1][0] = 0.00000000000001;
  B.matrix[1][1] = 0.00000000000001;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), 0);
  ck_assert(s21_eq_matrix(&B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test4) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 3.2;
  A.matrix[0][1] = 4.5;
  A.matrix[1][0] = 6.7;
  A.matrix[1][1] = 8.9;
  double number = 2.0;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 6.4;
  B.matrix[0][1] = 9.0;
  B.matrix[1][0] = 13.4;
  B.matrix[1][1] = 17.8;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), 0);
  ck_assert(s21_eq_matrix(&B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test5) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 0.0;
  double number = 2.0;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 0.0;
  B.matrix[0][1] = 0.0;
  B.matrix[1][0] = 0.0;
  B.matrix[1][1] = 0.0;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), 0);
  ck_assert(s21_eq_matrix(&B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test6) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);
  double mult_number = get_rand(-10e5, 10e5);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = m.matrix[i][j] * mult_number;
    }
  }
  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_number(&m, mult_number, &res), returnValue_Ok);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_test7) {
  matrix_t A, R, R2;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &R2);

  A.matrix[0][0] = 1.25;

  R2.matrix[0][0] = -5;

  s21_mult_number(&A, -4, &R);

  ck_assert(fabs(R.matrix[0][0] - R2.matrix[0][0]) < 1e-7);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}
END_TEST

START_TEST(mult_number_test8) {
  matrix_t A, R, R2;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R2);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 4.25;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;

  R2.matrix[0][0] = 1;
  R2.matrix[0][1] = 5;
  R2.matrix[0][2] = 9;
  R2.matrix[1][0] = 13;
  R2.matrix[1][1] = 17;
  R2.matrix[1][2] = 21;
  R2.matrix[2][0] = 25;
  R2.matrix[2][1] = 29;
  R2.matrix[2][2] = 33;

  s21_mult_number(&A, 4, &R);

  ck_assert_int_eq(s21_eq_matrix(&R, &R2), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}
END_TEST

START_TEST(mult_number_test9) {
  matrix_t A, R, R2;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &R2);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 4.25;
  A.matrix[1][2] = 5.25;

  R2.matrix[0][0] = 1;
  R2.matrix[0][1] = 5;
  R2.matrix[0][2] = 9;
  R2.matrix[1][0] = 13;
  R2.matrix[1][1] = 17;
  R2.matrix[1][2] = 21;

  s21_mult_number(&A, 4, &R);

  ck_assert_int_eq(s21_eq_matrix(&R, &R2), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}
END_TEST

START_TEST(mult_number_test10) {
  matrix_t *B = NULL;
  double num = 0;
  matrix_t *R = NULL;
  int res = s21_mult_number(B, num, R);
  ck_assert_int_eq(res, returnValue_IncorrectMatrixError);
}
END_TEST

Suite *mult_number(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("mult_number");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, mult_number_test1);
  tcase_add_test(tc_core, mult_number_test2);
  tcase_add_test(tc_core, mult_number_test3);
  tcase_add_test(tc_core, mult_number_test4);
  tcase_add_test(tc_core, mult_number_test5);
  tcase_add_test(tc_core, mult_number_test6);
  tcase_add_test(tc_core, mult_number_test7);
  tcase_add_test(tc_core, mult_number_test8);
  tcase_add_test(tc_core, mult_number_test9);
  tcase_add_test(tc_core, mult_number_test10);
  suite_add_tcase(s, tc_core);

  return s;
}
