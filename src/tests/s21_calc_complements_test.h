#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../headers/s21_common.h"
#include "../s21_matrix_oop.h"
#include "s21_test.h"

#endif

START_TEST(calc_complements_test1) {
  matrix_t inputMatrix = {0}, expectedMatrix = {0}, resultMatrix = {0};

  s21_create_matrix(3, 3, &expectedMatrix);
  s21_create_matrix(3, 3, &inputMatrix);

  expectedMatrix.matrix[0][0] = 1;
  expectedMatrix.matrix[0][1] = 2;
  expectedMatrix.matrix[0][2] = 3;
  expectedMatrix.matrix[1][0] = 0;
  expectedMatrix.matrix[1][1] = 4;
  expectedMatrix.matrix[1][2] = 2;
  expectedMatrix.matrix[2][0] = 5;
  expectedMatrix.matrix[2][1] = 2;
  expectedMatrix.matrix[2][2] = 1;

  inputMatrix.matrix[0][0] = 0;
  inputMatrix.matrix[0][1] = 10;
  inputMatrix.matrix[0][2] = -20;
  inputMatrix.matrix[1][0] = 4;
  inputMatrix.matrix[1][1] = -14;
  inputMatrix.matrix[1][2] = 8;
  inputMatrix.matrix[2][0] = -8;
  inputMatrix.matrix[2][1] = -2;
  inputMatrix.matrix[2][2] = 4;

  int returnValue = s21_calc_complements(&expectedMatrix, &resultMatrix);
  ck_assert_int_eq(returnValue, returnValue_Ok);
  ck_assert_int_eq(s21_eq_matrix(&resultMatrix, &inputMatrix), SUCCESS);

  s21_remove_matrix(&expectedMatrix);
  s21_remove_matrix(&resultMatrix);
  s21_remove_matrix(&inputMatrix);
}

END_TEST

START_TEST(calc_complements_test2) {
  matrix_t inputMatrix = {0}, expectedMatrix = {0}, resultMatrix = {0};

  s21_create_matrix(3, 3, &inputMatrix);
  s21_create_matrix(3, 3, &expectedMatrix);

  inputMatrix.matrix[0][0] = 5;
  inputMatrix.matrix[0][1] = -1;
  inputMatrix.matrix[0][2] = 1;
  inputMatrix.matrix[1][0] = 2;
  inputMatrix.matrix[1][1] = 3;
  inputMatrix.matrix[1][2] = 4;
  inputMatrix.matrix[2][0] = 1;
  inputMatrix.matrix[2][1] = 0;
  inputMatrix.matrix[2][2] = 3;

  s21_calc_complements(&inputMatrix, &resultMatrix);

  expectedMatrix.matrix[0][0] = 9;
  expectedMatrix.matrix[0][1] = -2;
  expectedMatrix.matrix[0][2] = -3;
  expectedMatrix.matrix[1][0] = 3;
  expectedMatrix.matrix[1][1] = 14;
  expectedMatrix.matrix[1][2] = -1;
  expectedMatrix.matrix[2][0] = -7;
  expectedMatrix.matrix[2][1] = -18;
  expectedMatrix.matrix[2][2] = 17;

  ck_assert_int_eq(s21_eq_matrix(&resultMatrix, &expectedMatrix), SUCCESS);

  s21_remove_matrix(&inputMatrix);
  s21_remove_matrix(&expectedMatrix);
  s21_remove_matrix(&resultMatrix);
}

END_TEST

START_TEST(calc_complements_test3) {
  matrix_t inputMatrix = {0}, expectedMatrix = {0}, resultMatrix = {0};

  s21_create_matrix(2, 3, &inputMatrix);

  inputMatrix.matrix[0][0] = 1;
  inputMatrix.matrix[0][1] = 2;
  inputMatrix.matrix[0][2] = 3;
  inputMatrix.matrix[1][0] = 0;
  inputMatrix.matrix[1][1] = 4;
  inputMatrix.matrix[1][2] = 2;

  int returnValue = s21_calc_complements(&inputMatrix, &resultMatrix);

  ck_assert_int_eq(returnValue, returnValue_CalculationError);

  s21_remove_matrix(&inputMatrix);
  s21_remove_matrix(&expectedMatrix);
  s21_remove_matrix(&resultMatrix);
}

END_TEST

START_TEST(calc_complements_test4) {
  matrix_t inputMatrix = {0}, expectedMatrix = {0}, resultMatrix = {0};
  s21_create_matrix(1, 1, &inputMatrix);
  s21_create_matrix(1, 1, &expectedMatrix);

  inputMatrix.matrix[0][0] = 5;

  s21_calc_complements(&inputMatrix, &resultMatrix);

  expectedMatrix.matrix[0][0] = 1;

  ck_assert_int_eq(s21_eq_matrix(&resultMatrix, &expectedMatrix), SUCCESS);

  s21_remove_matrix(&inputMatrix);
  s21_remove_matrix(&expectedMatrix);
  s21_remove_matrix(&resultMatrix);
}

END_TEST

START_TEST(calc_complements_test5) {
  matrix_t *expectedMatrix = NULL;
  matrix_t *resultMatrix = NULL;
  int returnValue = s21_calc_complements(expectedMatrix, resultMatrix);
  ck_assert_int_eq(returnValue, returnValue_IncorrectMatrixError);
}

END_TEST

START_TEST(calc_complements_test6) {
  matrix_t inputMatrix = {0}, expectedMatrix = {0}, resultMatrix = {0};
  s21_create_matrix(3, 3, &inputMatrix);
  s21_create_matrix(3, 3, &resultMatrix);
  inputMatrix.matrix[0][0] = 1.0;
  inputMatrix.matrix[0][1] = 2.0;
  inputMatrix.matrix[0][2] = 3.0;
  inputMatrix.matrix[1][0] = 0.0;
  inputMatrix.matrix[1][1] = 4.0;
  inputMatrix.matrix[1][2] = 2.0;
  inputMatrix.matrix[2][0] = 5.0;
  inputMatrix.matrix[2][1] = 2.0;
  inputMatrix.matrix[2][2] = 1.0;
  s21_calc_complements(&inputMatrix, &expectedMatrix);
  resultMatrix.matrix[0][0] = 0.0;
  resultMatrix.matrix[0][1] = 10.0;
  resultMatrix.matrix[0][2] = -20.0;
  resultMatrix.matrix[1][0] = 4.0;
  resultMatrix.matrix[1][1] = -14.0;
  resultMatrix.matrix[1][2] = 8.0;
  resultMatrix.matrix[2][0] = -8.0;
  resultMatrix.matrix[2][1] = -2.0;
  resultMatrix.matrix[2][2] = 4.0;
  int returnValue = s21_eq_matrix(&expectedMatrix, &resultMatrix);
  ck_assert_int_eq(returnValue, SUCCESS);
  s21_remove_matrix(&inputMatrix);
  s21_remove_matrix(&expectedMatrix);
  s21_remove_matrix(&resultMatrix);
}

END_TEST

START_TEST(calc_complements_test7) {
  matrix_t inputMatrix = {0}, expectedMatrix = {0}, resultMatrix = {0};
  s21_create_matrix(3, 3, &inputMatrix);
  s21_create_matrix(3, 3, &expectedMatrix);
  expectedMatrix.matrix[0][0] = 0;
  expectedMatrix.matrix[0][1] = 10;
  expectedMatrix.matrix[0][2] = -20;
  expectedMatrix.matrix[1][0] = 4;
  expectedMatrix.matrix[1][1] = -14;
  expectedMatrix.matrix[1][2] = 8;
  expectedMatrix.matrix[2][0] = -8;
  expectedMatrix.matrix[2][1] = -2;
  expectedMatrix.matrix[2][2] = 4;

  inputMatrix.matrix[0][0] = 1;
  inputMatrix.matrix[0][1] = 2;
  inputMatrix.matrix[0][2] = 3;
  inputMatrix.matrix[1][0] = 0;
  inputMatrix.matrix[1][1] = 4;
  inputMatrix.matrix[1][2] = 2;
  inputMatrix.matrix[2][0] = 5;
  inputMatrix.matrix[2][1] = 2;
  inputMatrix.matrix[2][2] = 1;
  s21_calc_complements(&inputMatrix, &resultMatrix);
  ck_assert_int_eq(s21_eq_matrix(&expectedMatrix, &resultMatrix), SUCCESS);
  s21_remove_matrix(&resultMatrix);
  s21_remove_matrix(&inputMatrix);
  s21_remove_matrix(&expectedMatrix);
}

END_TEST

START_TEST(calc_complements_test8) {
  matrix_t inputMatrix = {0};
  matrix_t expectedMatrix = {0};
  ck_assert_int_eq(s21_calc_complements(&inputMatrix, &expectedMatrix),
                   returnValue_IncorrectMatrixError);
}

END_TEST

START_TEST(calc_complements_test9) {
  matrix_t inputMatrix = {0};
  matrix_t expectedMatrix = {0};
  s21_create_matrix(1, 2, &inputMatrix);
  ck_assert_int_eq(s21_calc_complements(&inputMatrix, &expectedMatrix),
                   returnValue_CalculationError);
  s21_remove_matrix(&inputMatrix);
}

END_TEST

Suite *calc_complements(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("calc_complements");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, calc_complements_test1);
  tcase_add_test(tc_core, calc_complements_test2);
  tcase_add_test(tc_core, calc_complements_test3);
  tcase_add_test(tc_core, calc_complements_test4);
  tcase_add_test(tc_core, calc_complements_test5);
  tcase_add_test(tc_core, calc_complements_test6);
  tcase_add_test(tc_core, calc_complements_test7);
  tcase_add_test(tc_core, calc_complements_test8);
  tcase_add_test(tc_core, calc_complements_test9);
  suite_add_tcase(s, tc_core);
  return s;
}
