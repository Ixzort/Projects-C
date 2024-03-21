#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *ans) {
  if (rows <= 0 || columns <= 0 || is_null(ans)) {
    return MATRIX_ERR;
  }
  ans->matrix = (double **)calloc(rows, sizeof(double *));
  for (int i = 0; i < rows; i++) {
    ans->matrix[i] = (double *)calloc(columns, sizeof(double));
  }
  ans->columns = columns;
  ans->rows = rows;
  return OK;
}