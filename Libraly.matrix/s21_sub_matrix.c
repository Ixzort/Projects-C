#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *ans) {
  if (is_null(A) || is_null(B) || is_null(ans)) {
    return MATRIX_ERR;
  } else if (A->columns != B->columns || A->rows != B->rows || inf_or_nan(A) ||
             inf_or_nan(B)) {
    return CALC_ERR;
  }
  s21_create_matrix(A->rows, A->columns, ans);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      ans->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return OK;
}
