#include "tests_main.h"

START_TEST(mult_number_part_1) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;

  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  ck_assert_int_eq(s21_mult_number(&A, 2, &result), 0);
  ck_assert_double_eq(result.matrix[0][0], 2);
  ck_assert_double_eq(result.matrix[0][1], 4);

  ck_assert_double_eq(result.matrix[1][0], 6);
  ck_assert_double_eq(result.matrix[1][1], 8);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_part_2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;

  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  ck_assert_int_eq(s21_mult_number(&A, 2, NULL), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_part_3) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0.0 / 0.0;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;

  ck_assert_int_eq(s21_mult_number(&A, 2, &result), 2);
  s21_remove_matrix(&A);
}
END_TEST

Suite *mult_number() {
  Suite *s = suite_create("mult_number");
  TCase *tc_create = tcase_create("mult_number");
  tcase_add_test(tc_create, mult_number_part_1);
  tcase_add_test(tc_create, mult_number_part_2);
  tcase_add_test(tc_create, mult_number_part_3);
  suite_add_tcase(s, tc_create);
  return s;
}