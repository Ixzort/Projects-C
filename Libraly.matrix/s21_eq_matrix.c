#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int err = SUCCESS;

  if (A->columns != B->columns || A->rows != B->rows || is_null(A) ||
      is_null(B)) {
    return FAILURE;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 0.0000001) {
        err = FAILURE;
        i = A->rows;
        j = A->columns;
      }
    }
  }

  return err;
}
