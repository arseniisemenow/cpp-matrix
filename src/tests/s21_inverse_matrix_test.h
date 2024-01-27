#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../headers/s21_common.h"
#include "../s21_matrix_oop.h"
#include "s21_test.h"

#endif

START_TEST(inverse_matrix_test1) {
  matrix_t input = {0}, result = {0}, expected = {0};
  s21_create_matrix(3, 3, &input);
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 44300.0 / 367429.0;
  expected.matrix[0][1] = -236300.0 / 367429.0;
  expected.matrix[0][2] = 200360.0 / 367429.0;
  expected.matrix[1][0] = 20600.0 / 367429.0;
  expected.matrix[1][1] = 56000.0 / 367429.0;
  expected.matrix[1][2] = -156483.0 / 367429.0;
  expected.matrix[2][0] = 30900.0 / 367429.0;
  expected.matrix[2][1] = 84000.0 / 367429.0;
  expected.matrix[2][2] = -51010.0 / 367429.0;

  input.matrix[0][0] = 2.8;
  input.matrix[0][1] = 1.3;
  input.matrix[0][2] = 7.01;
  input.matrix[1][0] = -1.03;
  input.matrix[1][1] = -2.3;
  input.matrix[1][2] = 3.01;
  input.matrix[2][0] = 0;
  input.matrix[2][1] = -3;
  input.matrix[2][2] = 2;

  s21_inverse_matrix(&input, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&input);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

END_TEST

START_TEST(inverse_matrix_test2) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;

  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B;
  s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&B, &C), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}

END_TEST

START_TEST(inverse_matrix_test3) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  matrix_t res = {0};
  s21_inverse_matrix(&m, &res);

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);

  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
  s21_remove_matrix(&m);
}

END_TEST

START_TEST(inverse_matrix_test4) {
  matrix_t inputMatrix = {0};
  matrix_t expectedMatrix = {0};
  matrix_t resultMatrix = {0};

  s21_create_matrix(3, 3, &inputMatrix);
  s21_create_matrix(3, 3, &expectedMatrix);

  inputMatrix.matrix[0][0] = 2;
  inputMatrix.matrix[0][1] = 5;
  inputMatrix.matrix[0][2] = 7;

  inputMatrix.matrix[1][0] = 6;
  inputMatrix.matrix[1][1] = 3;
  inputMatrix.matrix[1][2] = 4;

  inputMatrix.matrix[2][0] = 5;
  inputMatrix.matrix[2][1] = -2;
  inputMatrix.matrix[2][2] = -3;

  expectedMatrix.matrix[0][0] = 1;
  expectedMatrix.matrix[0][1] = -1;
  expectedMatrix.matrix[0][2] = 1;

  expectedMatrix.matrix[1][0] = -38;
  expectedMatrix.matrix[1][1] = 41;
  expectedMatrix.matrix[1][2] = -34;

  expectedMatrix.matrix[2][0] = 27;
  expectedMatrix.matrix[2][1] = -29;
  expectedMatrix.matrix[2][2] = 24;

  int code = s21_inverse_matrix(&inputMatrix, &resultMatrix);

  ck_assert_int_eq(s21_eq_matrix(&resultMatrix, &expectedMatrix), SUCCESS);
  ck_assert_int_eq(code, returnValue_Ok);

  s21_remove_matrix(&inputMatrix);
  s21_remove_matrix(&resultMatrix);
  s21_remove_matrix(&expectedMatrix);
}

END_TEST

START_TEST(inverse_matrix_test5) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 4, &m);
  if (!codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, returnValue_CalculationError);
    s21_remove_matrix(&m);
  }
}

END_TEST

START_TEST(inverse_matrix_test6) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (!codec) {
    m.matrix[0][0] = 1431.12312331;
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
    ck_assert_int_eq(code, returnValue_Ok);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}

END_TEST

START_TEST(inverse_matrix_test7) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (!codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, returnValue_CalculationError);
    s21_remove_matrix(&m);
  }
}

END_TEST

START_TEST(inverse_matrix_test8) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, returnValue_IncorrectMatrixError);
}

END_TEST

START_TEST(inverse_matrix_test9) {
  matrix_t first = {0};
  matrix_t desiredResult = {0};
  matrix_t myResult = {0};
  s21_create_matrix(3, 3, &first);
  s21_create_matrix(3, 3, &desiredResult);

  first.matrix[0][0] = 2;
  first.matrix[0][1] = 5;
  first.matrix[0][2] = 7;

  first.matrix[1][0] = 6;
  first.matrix[1][1] = 3;
  first.matrix[1][2] = 4;

  first.matrix[2][0] = 5;
  first.matrix[2][1] = -2;
  first.matrix[2][2] = -3;

  desiredResult.matrix[0][0] = 1;
  desiredResult.matrix[0][1] = -1;
  desiredResult.matrix[0][2] = 1;

  desiredResult.matrix[1][0] = -38;
  desiredResult.matrix[1][1] = 41;
  desiredResult.matrix[1][2] = -34;

  desiredResult.matrix[2][0] = 27;
  desiredResult.matrix[2][1] = -29;
  desiredResult.matrix[2][2] = 24;

  int myReturnValue = s21_inverse_matrix(&first, &myResult);
  int desiredReturnValue = returnValue_Ok;
  ck_assert_int_eq(myReturnValue, desiredReturnValue);
  ck_assert_int_eq(s21_eq_matrix(&myResult, &desiredResult), SUCCESS);

  s21_remove_matrix(&first);
  s21_remove_matrix(&desiredResult);
  s21_remove_matrix(&myResult);
}
END_TEST

START_TEST(inverse_matrix_test10) {
  matrix_t first = {0};
  matrix_t myResult = {0};
  s21_create_matrix(1, 3, &first);

  int myReturnValue = s21_inverse_matrix(&first, &myResult);
  int desiredReturnValue = returnValue_CalculationError;
  ck_assert_int_eq(myReturnValue, desiredReturnValue);

  s21_remove_matrix(&first);
  s21_remove_matrix(&myResult);
}
END_TEST

START_TEST(inverse_matrix_test11) {
  matrix_t myResult = {0};
  int myReturnValue = s21_inverse_matrix(NULL, &myResult);
  int desiredReturnValue = returnValue_IncorrectMatrixError;
  ck_assert_int_eq(myReturnValue, desiredReturnValue);
}
END_TEST

START_TEST(inverse_matrix_test12) {
  matrix_t first = {0};
  matrix_t desiredResult = {0};
  matrix_t myResult = {0};
  s21_create_matrix(1, 1, &first);
  s21_create_matrix(1, 1, &desiredResult);

  first.matrix[0][0] = 4;

  desiredResult.matrix[0][0] = 0.25;

  int myReturnValue = s21_inverse_matrix(&first, &myResult);
  int desiredReturnValue = returnValue_Ok;
  ck_assert_int_eq(myReturnValue, desiredReturnValue);
  ck_assert_int_eq(s21_eq_matrix(&myResult, &desiredResult), SUCCESS);

  s21_remove_matrix(&first);
  s21_remove_matrix(&desiredResult);
  s21_remove_matrix(&myResult);
}
END_TEST

START_TEST(inverse_matrix_test13) {
  matrix_t first = {0};
  matrix_t myResult = {0};
  s21_create_matrix(1, 1, &first);

  first.matrix[0][0] = 0;

  int myReturnValue = s21_inverse_matrix(&first, &myResult);
  int desiredReturnValue = returnValue_CalculationError;
  ck_assert_int_eq(myReturnValue, desiredReturnValue);

  s21_remove_matrix(&first);
  s21_remove_matrix(&myResult);
}
END_TEST

Suite *inverse_matrix(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("inverse_matrix");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, inverse_matrix_test1);
  tcase_add_test(tc_core, inverse_matrix_test2);
  tcase_add_test(tc_core, inverse_matrix_test3);
  tcase_add_test(tc_core, inverse_matrix_test4);
  tcase_add_test(tc_core, inverse_matrix_test5);
  tcase_add_test(tc_core, inverse_matrix_test6);
  tcase_add_test(tc_core, inverse_matrix_test7);
  tcase_add_test(tc_core, inverse_matrix_test8);
  tcase_add_test(tc_core, inverse_matrix_test9);
  tcase_add_test(tc_core, inverse_matrix_test10);
  tcase_add_test(tc_core, inverse_matrix_test11);
  tcase_add_test(tc_core, inverse_matrix_test12);
  tcase_add_test(tc_core, inverse_matrix_test13);
  suite_add_tcase(s, tc_core);
  return s;
}
