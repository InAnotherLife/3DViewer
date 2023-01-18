#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

typedef struct matrix_str {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

matrix_t create_matrix(int rows, int columns);
void remove_matrix(matrix_t *matr);
void move_matrix(matrix_t *A, double dx, double dy, double dz);
void rotate_x(matrix_t *A, double angle);
void rotate_y(matrix_t *A, double angle);
void rotate_z(matrix_t *A, double angle);
void scale_matrix(matrix_t *A, double scale);
int is_correct_matrix(matrix_t *A);

#ifdef __cplusplus
}
#endif

#endif  // SRC_MATRIX_H_
