#include "tests_main.h"

START_TEST(sub_matrix_part_1) {
  matrix_t A, result;

  ck_assert_int_eq(s21_sub_matrix(&A, NULL, &result), 1);
}
END_TEST

START_TEST(sub_matrix_part_2) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = B.matrix[0][0] = 1;
  A.matrix[0][1] = B.matrix[0][1] = 2;
  A.matrix[0][2] = B.matrix[0][2] = 3;
  A.matrix[1][0] = B.matrix[1][0] = 4;
  A.matrix[1][1] = B.matrix[1][1] = 5;
  A.matrix[1][2] = B.matrix[1][2] = 6;
  A.matrix[2][0] = B.matrix[2][0] = 7;
  A.matrix[2][1] = B.matrix[2][1] = 8;
  A.matrix[2][2] = B.matrix[2][2] = 9;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  ck_assert_double_eq(result.matrix[0][0], 0);
  ck_assert_double_eq(result.matrix[0][1], 0);
  ck_assert_double_eq(result.matrix[0][2], 0);

  ck_assert_double_eq(result.matrix[1][0], 0);
  ck_assert_double_eq(result.matrix[1][1], 0);
  ck_assert_double_eq(result.matrix[1][2], 0);

  ck_assert_double_eq(result.matrix[2][0], 0);
  ck_assert_double_eq(result.matrix[2][1], 0);
  ck_assert_double_eq(result.matrix[2][2], 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_part_3) {
  matrix_t A, B, result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_part_4) {
  matrix_t A, B, result;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(1, 5, &B);

  A.matrix[0][0] = B.matrix[0][0] = 1;
  A.matrix[0][1] = B.matrix[0][1] = 2;
  A.matrix[0][2] = B.matrix[0][2] = 3;
  A.matrix[0][3] = B.matrix[0][3] = 4;
  A.matrix[0][4] = B.matrix[0][4] = 5;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);

  ck_assert_double_eq(result.matrix[0][0], 0);
  ck_assert_double_eq(result.matrix[0][1], 0);
  ck_assert_double_eq(result.matrix[0][2], 0);
  ck_assert_double_eq(result.matrix[0][3], 0);
  ck_assert_double_eq(result.matrix[0][4], 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *sub_matrix() {
  Suite *s = suite_create("sub_matrix");
  TCase *tc_create = tcase_create("sub_matrix");
  tcase_add_test(tc_create, sub_matrix_part_1);
  tcase_add_test(tc_create, sub_matrix_part_2);
  tcase_add_test(tc_create, sub_matrix_part_3);
  tcase_add_test(tc_create, sub_matrix_part_4);
  suite_add_tcase(s, tc_create);
  return s;
}