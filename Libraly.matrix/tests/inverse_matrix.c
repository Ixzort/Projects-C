#include "tests_main.h"

START_TEST(inverse_matrix_part_1) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;

  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), 0);
  ck_assert_int_eq(result.matrix[0][0], 1);
  ck_assert_int_eq(result.matrix[0][1], -1);
  ck_assert_int_eq(result.matrix[0][2], 1);

  ck_assert_int_eq(result.matrix[1][0], -38);
  ck_assert_int_eq(result.matrix[1][1], 41);
  ck_assert_int_eq(result.matrix[1][2], -34);

  ck_assert_int_eq(result.matrix[2][0], 27);
  ck_assert_int_eq(result.matrix[2][1], -29);
  ck_assert_int_eq(result.matrix[2][2], 24);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_part_2) {
  matrix_t A, result;
  s21_create_matrix(3, 2, &A);

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_part_3) {
  matrix_t A;
  s21_create_matrix(3, 2, &A);

  ck_assert_int_eq(s21_inverse_matrix(&A, NULL), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_part_4) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), 2);
  s21_remove_matrix(&A);
}
END_TEST

Suite *inverse_matrix() {
  Suite *s = suite_create("inverse_matrix");
  TCase *tc_create = tcase_create("inverse_matrix");
  tcase_add_test(tc_create, inverse_matrix_part_1);
  tcase_add_test(tc_create, inverse_matrix_part_2);
  tcase_add_test(tc_create, inverse_matrix_part_3);
  tcase_add_test(tc_create, inverse_matrix_part_4);
  suite_add_tcase(s, tc_create);
  return s;
}