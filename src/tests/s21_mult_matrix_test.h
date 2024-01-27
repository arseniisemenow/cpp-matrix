#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../headers/s21_common.h"
#include "../s21_matrix_oop.h"
#include "s21_test.h"

#endif

START_TEST(mult_matrix_test1) {
  matrix_t *A = NULL, B, result;
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(A, &B, &result), 1);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test2) {
  matrix_t A, *B = NULL, result;
  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_mult_matrix(&A, B, &result), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_matrix_test3) {
  matrix_t A, B, *result = NULL;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test4) {
  matrix_t A, B, R, R2;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &R2);

  A.matrix[0][0] = -1;
  B.matrix[0][0] = 2;

  R2.matrix[0][0] = -2;

  s21_mult_matrix(&A, &B, &R);

  ck_assert(fabs(R.matrix[0][0] - R2.matrix[0][0]) < 1e-7);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}
END_TEST

START_TEST(mult_matrix_test5) {
  matrix_t A, B, R, R2;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &R2);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 6;
  A.matrix[2][1] = 7;

  B.matrix[0][0] = 9;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 7;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 4;

  R2.matrix[0][0] = 6;
  R2.matrix[0][1] = 5;
  R2.matrix[0][2] = 4;
  R2.matrix[1][0] = 51;
  R2.matrix[1][1] = 44;
  R2.matrix[1][2] = 37;
  R2.matrix[2][0] = 96;
  R2.matrix[2][1] = 83;
  R2.matrix[2][2] = 70;

  s21_mult_matrix(&A, &B, &R);

  ck_assert_int_eq(s21_eq_matrix(&R, &R2), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}
END_TEST

START_TEST(mult_matrix_test6) {
  matrix_t *A = NULL, *B = NULL, *R = NULL;
  ck_assert_int_eq(s21_mult_matrix(A, B, R), returnValue_IncorrectMatrixError);
}
END_TEST

Suite *mult_matrix(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("mult_matrix");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, mult_matrix_test1);
  tcase_add_test(tc_core, mult_matrix_test2);
  tcase_add_test(tc_core, mult_matrix_test3);
  tcase_add_test(tc_core, mult_matrix_test4);
  tcase_add_test(tc_core, mult_matrix_test5);
  tcase_add_test(tc_core, mult_matrix_test6);
  suite_add_tcase(s, tc_core);
  return s;
}
