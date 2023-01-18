#include "matrix.h"

matrix_t create_matrix(int rows, int columns) {
  matrix_t matr = {NULL, rows, columns};
  if (rows > 0 && columns > 0) {
    matr.matrix = (double **)calloc(rows, sizeof(double));
    for (int i = 0; i < rows; i++) {
      matr.matrix[i] = (double *)calloc(columns, sizeof(double));
      for (int j = 0; j < columns; j++) {
        matr.matrix[i][j] = 0.0;
      }
    }
  }
  return matr;
}

void remove_matrix(matrix_t *matr) {
  if (matr) {
    for (int i = 0; i < matr->rows; i++) {
      if (matr->matrix[i]) free(matr->matrix[i]);
    }
    free(matr->matrix);
  }
}

void move_matrix(matrix_t *A, double delta_x, double delta_y, double delta_z) {
  if (is_correct_matrix(A)) {
    for (int i = 0; i < A->rows; i++) {
      if (delta_x != 0) A->matrix[i][0] += delta_x;
      if (delta_y != 0) A->matrix[i][1] += delta_y;
      if (delta_z != 0) A->matrix[i][2] += delta_z;
    }
  }
}

void rotate_x(matrix_t *A, double angle) {
  if (is_correct_matrix(A) && angle != 0) {
    double angRad = angle * PI / 180;
    for (int i = 0; i < A->rows; i++) {
      double currentY = A->matrix[i][1], currentZ = A->matrix[i][2];
      A->matrix[i][1] = currentY * cos(angRad) - currentZ * sin(angRad);
      A->matrix[i][2] = currentZ * cos(angRad) + currentY * sin(angRad);
    }
  }
}

void rotate_y(matrix_t *A, double angle) {
  if (is_correct_matrix(A) && angle != 0) {
    double angRad = angle * PI / 180;
    for (int i = 0; i < A->rows; i++) {
      double currentX = A->matrix[i][0], currentZ = A->matrix[i][2];
      A->matrix[i][0] = currentX * cos(angRad) - currentZ * sin(angRad);
      A->matrix[i][2] = currentZ * cos(angRad) + currentX * sin(angRad);
    }
  }
}

void rotate_z(matrix_t *A, double angle) {
  if (is_correct_matrix(A) && angle != 0) {
    double angRad = angle * PI / 180;
    for (int i = 0; i < A->rows; i++) {
      double currentX = A->matrix[i][0], currentY = A->matrix[i][1];
      A->matrix[i][0] = currentX * cos(angRad) - currentY * sin(angRad);
      A->matrix[i][1] = currentY * cos(angRad) + currentX * sin(angRad);
    }
  }
}

void scale_matrix(matrix_t *A, double scale) {
  if (is_correct_matrix(A)) {
    if (scale > 0) {
      for (int i = 0; i < A->rows; i++) {
        A->matrix[i][0] *= scale;
        A->matrix[i][1] *= scale;
        A->matrix[i][2] *= scale;
      }
    } else if (scale < 0) {
      scale *= -1;
      for (int i = 0; i < A->rows; i++) {
        A->matrix[i][0] /= scale;
        A->matrix[i][1] /= scale;
        A->matrix[i][2] /= scale;
      }
    }
  }
}

int is_correct_matrix(matrix_t *A) {
  int res = 0;
  if (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0) res = 1;
  return res;
}
