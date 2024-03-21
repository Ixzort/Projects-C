#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *ans) {
  if (is_null(A) || is_null(B) || is_null(ans)) {
    return MATRIX_ERR;
  } else if (A->columns != B->rows || inf_or_nan(A) || inf_or_nan(B)) {
    return CALC_ERR;
  }
  s21_create_matrix(A->rows, B->columns, ans);
  for (int i = 0; i < ans->rows; i++) {
    for (int j = 0; j < ans->columns; j++) {
      for (int k = 0; k < A->columns; k++) {
        ans->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return OK;
}
