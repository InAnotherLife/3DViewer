#ifndef SRC_3DVIEWER_H_
#define SRC_3DVIEWER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

#define MAX_LEN_STR 500

typedef struct data_str {
  unsigned int count_rows_vertexes;
  unsigned int count_rows_facets;
  unsigned int count_indexes_facets;
  unsigned int count_num_facets;
  unsigned int count_row_matrix;
} data_t;

void get_file_info(FILE *fileRead, data_t *data);
void get_str(char *fileName, matrix_t *matr, data_t *data, unsigned int *arr);
void fill_matrix_or_array(char *str, matrix_t *matr, data_t *data,
                          unsigned int *arr);
void get_coords_facets(matrix_t *matr, data_t *data, const unsigned int *arr1,
                       double *arr2);
int is_num(double num);

#ifdef __cplusplus
}
#endif

#endif  // SRC_3DVIEWER_H_
