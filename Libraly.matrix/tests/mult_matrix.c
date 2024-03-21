#include "tests_main.h"

START_TEST(mult_matrix_part_1) {
  matrix_t A, B, result;

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;

  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;

  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);

  ck_assert_double_eq(result.matrix[0][0], 9);
  ck_assert_double_eq(result.matrix[0][1], 11);
  ck_assert_double_eq(result.matrix[0][2], 17);

  ck_assert_double_eq(result.matrix[1][0], 12);
  ck_assert_double_eq(result.matrix[1][1], 13);
  ck_assert_double_eq(result.matrix[1][2], 22);

  ck_assert_double_eq(result.matrix[2][0], 15);
  ck_assert_double_eq(result.matrix[2][1], 15);
  ck_assert_double_eq(result.matrix[2][2], 27);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_part_2) {
  matrix_t A, B, result;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 3, &B);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_part_3) {
  matrix_t A, B;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 3, &B);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *mult_matrix() {
  Suite *s = suite_create("mult_matrix");
  TCase *tc_create = tcase_create("mult_matrix");
  tcase_add_test(tc_create, mult_matrix_part_1);
  tcase_add_test(tc_create, mult_matrix_part_2);
  tcase_add_test(tc_create, mult_matrix_part_3);
  suite_add_tcase(s, tc_create);
  return s;
}