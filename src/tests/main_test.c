#include "main_test.h"

int main() {
  int errcode = 0;
  case_test(calc_complements(), &errcode);
  case_test(create_matrix(), &errcode);
  case_test(determinant(), &errcode);
  case_test(eq_matrix(), &errcode);
  case_test(inverse_matrix(), &errcode);
  case_test(mult_matrix(), &errcode);
  case_test(mult_number(), &errcode);
  case_test(sub_matrix(), &errcode);
  case_test(sum_matrix(), &errcode);
  case_test(transpose(), &errcode);
  return errcode;
}
