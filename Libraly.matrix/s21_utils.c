#include "s21_matrix.h"

int inf_or_nan(matrix_t* m) {
  int res = OK;
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->columns; j++) {
      if (isinf(m->matrix[i][j]) || isnan(m->matrix[i][j])) {
        res = 1;
        i = m->rows;
        j = m->columns;
      }
    }
  }
  return res;
}

int is_null(matrix_t* pointer) { return pointer == NULL; }

void cut_minor_matrix(matrix_t* minor, matrix_t A, int row, int col) {
  for (int i = 0, m = 0; i < A.rows; i++) {
    for (int j = 0, n = 0; j < A.columns; j++) {
      if (i != row && j != col) {
        minor->matrix[m][n] = A.matrix[i][j];
        n++;
        if (n == minor->columns) {
          m++;
          n = 0;
        }
      }
    }
  }
}
