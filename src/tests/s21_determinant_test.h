#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../headers/s21_common.h"
#include "../s21_matrix_oop.h"
#include "s21_test.h"

#endif

START_TEST(determinant_test1) {
  matrix_t A;
  double B, R = 1.25;
  s21_create_matrix(1, 1, &A);

  A.matrix[0][0] = 1.25;

  s21_determinant(&A, &B);
  ck_assert((fabs(B) - fabs(R)) < 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test2) {
  matrix_t A;
  double B, R = -69;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;

  s21_determinant(&A, &B);

  ck_assert((fabs(B) - fabs(R)) < 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test3) {
  matrix_t A;
  double B, R = -2;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = -5;
  A.matrix[1][1] = -7;

  s21_determinant(&A, &B);

  ck_assert((fabs(B) - fabs(R)) < 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test4) {
  matrix_t A;
  double B, R = -2;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -6;
  A.matrix[1][0] = -5;
  A.matrix[1][1] = -7;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = -6;

  s21_determinant(&A, &B);

  ck_assert((fabs(B) - fabs(R)) < 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test5) {
  matrix_t A;
  double B, R = 25;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = -3;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -6;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = -7;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = -4;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = -6;

  s21_determinant(&A, &B);

  ck_assert((fabs(B) - fabs(R)) < 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test6) {
  matrix_t A;
  double B, R = 23;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = -3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = -6;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = -5;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = -4;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = -6;

  s21_determinant(&A, &B);

  ck_assert((fabs(B) - fabs(R)) < 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test7) {
  matrix_t A;
  double B, R = -8;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = -3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = -5;
  A.matrix[1][2] = -7;
  A.matrix[2][0] = -4;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 5;

  s21_determinant(&A, &B);

  ck_assert((fabs(B) - fabs(R)) < 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test8) {
  matrix_t A;
  double B, R = 18;
  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = 3;
  A.matrix[0][1] = -3;
  A.matrix[0][2] = -5;
  A.matrix[0][3] = 8;
  A.matrix[1][0] = -3;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = -6;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = -5;
  A.matrix[2][2] = -7;
  A.matrix[2][3] = 5;
  A.matrix[3][0] = -4;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 5;
  A.matrix[3][3] = -6;

  s21_determinant(&A, &B);

  ck_assert((fabs(B) - fabs(R)) < 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test9) {
  matrix_t A;
  double B, R = -69.0 / 4.0;
  s21_create_matrix(5, 5, &A);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[0][3] = 3.25;
  A.matrix[0][4] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 5.25;
  A.matrix[1][3] = 5.25;
  A.matrix[1][4] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;
  A.matrix[2][3] = 6.25;
  A.matrix[2][4] = 6.25;
  A.matrix[3][0] = 6.25;
  A.matrix[3][1] = 7.25;
  A.matrix[3][2] = 8.25;
  A.matrix[3][3] = 6.25;
  A.matrix[3][4] = 7.25;
  A.matrix[4][0] = 6.25;
  A.matrix[4][1] = 7.25;
  A.matrix[4][2] = 8.25;
  A.matrix[4][3] = 6;
  A.matrix[4][4] = 8.25;

  s21_determinant(&A, &B);

  ck_assert((fabs(B) - fabs(R)) < 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test10) {
  matrix_t A;
  double B;
  s21_create_matrix(4, 5, &A);
  int res = s21_determinant(&A, &B);
  ck_assert_int_eq(res, returnValue_CalculationError);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test11) {
  matrix_t a;
  double number;
  s21_create_matrix(4, 4, &a);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[0][3] = 13;

  a.matrix[1][0] = 4;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 6;
  a.matrix[1][3] = 16;

  a.matrix[2][0] = 7;
  a.matrix[2][1] = 8;
  a.matrix[2][2] = 90;
  a.matrix[2][3] = 19;

  a.matrix[3][0] = 1;
  a.matrix[3][1] = 7;
  a.matrix[3][2] = 7;
  a.matrix[3][3] = 17;

  s21_determinant(&a, &number);
  ck_assert_ldouble_eq_tol(number, 13608, S21_EPSILON);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant_test12) {
  matrix_t *B = NULL;
  double re = 0;
  int res = s21_determinant(B, &re);
  ck_assert_int_eq(res, returnValue_IncorrectMatrixError);
}
END_TEST

START_TEST(determinant_test13) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j;

  double res;

  int code = s21_determinant(&m, &res);

  ck_assert_ldouble_eq_tol(res, 0, S21_EPSILON);
  ck_assert_int_eq(code, returnValue_Ok);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test14) {
  const int size = 4;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j + i;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, S21_EPSILON);
  ck_assert_int_eq(code, returnValue_Ok);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test15) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][1] = 6;
  m.matrix[0][2] = -2;
  m.matrix[0][3] = -1;
  m.matrix[0][4] = 5;

  m.matrix[1][3] = -9;
  m.matrix[1][4] = -7;

  m.matrix[2][1] = 15;
  m.matrix[2][2] = 35;

  m.matrix[3][1] = -1;
  m.matrix[3][2] = -11;
  m.matrix[3][3] = -2;
  m.matrix[3][4] = 1;

  m.matrix[4][0] = -2;
  m.matrix[4][1] = -2;
  m.matrix[4][2] = 3;
  m.matrix[4][4] = -2;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 2480, S21_EPSILON);
  ck_assert_int_eq(code, returnValue_Ok);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test16) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 7;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 1;
  m.matrix[2][0] = 9;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 1;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -32, S21_EPSILON);
  ck_assert_int_eq(code, returnValue_Ok);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test17) {
  const int size = 2;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = -5;
  m.matrix[0][1] = -4;
  m.matrix[1][0] = -2;
  m.matrix[1][1] = -3;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 7, S21_EPSILON);
  ck_assert_int_eq(code, returnValue_Ok);

  s21_remove_matrix(&m);
}
END_TEST

Suite *determinant(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("determinant");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, determinant_test1);
  tcase_add_test(tc_core, determinant_test2);
  tcase_add_test(tc_core, determinant_test3);
  tcase_add_test(tc_core, determinant_test4);
  tcase_add_test(tc_core, determinant_test5);
  tcase_add_test(tc_core, determinant_test6);
  tcase_add_test(tc_core, determinant_test7);
  tcase_add_test(tc_core, determinant_test8);
  tcase_add_test(tc_core, determinant_test9);
  tcase_add_test(tc_core, determinant_test10);
  tcase_add_test(tc_core, determinant_test11);
  tcase_add_test(tc_core, determinant_test12);
  tcase_add_test(tc_core, determinant_test13);
  tcase_add_test(tc_core, determinant_test14);
  tcase_add_test(tc_core, determinant_test15);
  tcase_add_test(tc_core, determinant_test16);
  tcase_add_test(tc_core, determinant_test17);
  suite_add_tcase(s, tc_core);
  return s;
}
