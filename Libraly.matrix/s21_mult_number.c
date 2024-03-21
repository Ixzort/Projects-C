#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *ans) {
  if (is_null(A) || is_null(ans)) {
    return MATRIX_ERR;
  } else if (isinf(number) || isnan(number) || inf_or_nan(A)) {
    return CALC_ERR;
  }
  s21_create_matrix(A->rows, A->columns, ans);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      ans->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return OK;
}