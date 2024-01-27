#ifndef TEST_HEADER_
#define TEST_HEADER_
#include "../headers/s21_common.h"
#include "../s21_matrix_oop.h"
#include "s21_test.h"
#endif

START_TEST(sub_matrix_test1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_test2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 3, &B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_test3) {
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 3, &B);
  int code = s21_sub_matrix(NULL, &B, &result);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_test4) {
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 3, &A);
  int code = s21_sub_matrix(&A, NULL, &result);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(sub_matrix_test5) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  int code = s21_sub_matrix(&A, &B, NULL);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_test6) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_test7) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(0, 3, &A);
  s21_create_matrix(0, 3, &B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_test8) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 0, &A);
  s21_create_matrix(3, 0, &B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_test9) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(1000, 1000, &A);
  s21_create_matrix(1000, 1000, &B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_test10) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = -1;
  B.matrix[0][0] = -1;
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(result.matrix[0][0], 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_test11) {
  matrix_t A, B, R, R2;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &R2);

  A.matrix[0][0] = 1.25;
  B.matrix[0][0] = 2.25;

  R2.matrix[0][0] = -1;

  s21_sub_matrix(&A, &B, &R);

  ck_assert(fabs(R.matrix[0][0] - R2.matrix[0][0]) < 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}
END_TEST

START_TEST(sub_matrix_test12) {
  matrix_t A, B, R, R2;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
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

  B.matrix[0][0] = 9.25;
  B.matrix[0][1] = 8.25;
  B.matrix[0][2] = 7.25;
  B.matrix[1][0] = 6.25;
  B.matrix[1][1] = 5.25;
  B.matrix[1][2] = 4.25;
  B.matrix[2][0] = 3.25;
  B.matrix[2][1] = 2.25;
  B.matrix[2][2] = 1.25;

  R2.matrix[0][0] = -9.0;
  R2.matrix[0][1] = -7.0;
  R2.matrix[0][2] = -5.0;
  R2.matrix[1][0] = -3.0;
  R2.matrix[1][1] = -1.0;
  R2.matrix[1][2] = 1.0;
  R2.matrix[2][0] = 3.0;
  R2.matrix[2][1] = 5.0;
  R2.matrix[2][2] = 7.0;

  s21_sub_matrix(&A, &B, &R);

  ck_assert_int_eq(s21_eq_matrix(&R, &R2), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}
END_TEST

START_TEST(sub_matrix_test13) {
  matrix_t A, B, R;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(2, 1, &B);

  A.matrix[0][0] = 1.25;
  B.matrix[0][0] = 2.25;

  int res = s21_sub_matrix(&A, &B, &R);

  ck_assert_int_eq(res, returnValue_CalculationError);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_test14) {
  matrix_t *A = NULL;
  matrix_t *B = NULL;
  matrix_t *R = NULL;
  int res = s21_sub_matrix(A, B, R);
  ck_assert_int_eq(res, returnValue_IncorrectMatrixError);
}
END_TEST

Suite *sub_matrix(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("sub_matrix");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sub_matrix_test1);
  tcase_add_test(tc_core, sub_matrix_test2);
  tcase_add_test(tc_core, sub_matrix_test3);
  tcase_add_test(tc_core, sub_matrix_test4);
  tcase_add_test(tc_core, sub_matrix_test5);
  tcase_add_test(tc_core, sub_matrix_test6);
  tcase_add_test(tc_core, sub_matrix_test7);
  tcase_add_test(tc_core, sub_matrix_test8);
  tcase_add_test(tc_core, sub_matrix_test9);
  tcase_add_test(tc_core, sub_matrix_test10);
  tcase_add_test(tc_core, sub_matrix_test11);
  tcase_add_test(tc_core, sub_matrix_test12);
  tcase_add_test(tc_core, sub_matrix_test13);
  tcase_add_test(tc_core, sub_matrix_test14);
  suite_add_tcase(s, tc_core);
  return s;
}
