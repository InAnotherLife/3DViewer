#include "3dviewer.h"

void get_file_info(FILE *file_read, data_t *data) {
  char str[MAX_LEN_STR];
  while (fgets(str, sizeof(str), file_read)) {
    if (!strncmp(str, "v ", 2)) data->count_rows_vertexes++;
    if (!strncmp(str, "f ", 2)) {
      data->count_rows_facets++;
      char *token, *rest = NULL;
      for (token = strtok_r(str, " ", &rest); token != NULL;
           token = strtok_r(NULL, " ", &rest)) {
        if (is_num(token[0])) data->count_indexes_facets++;
      }
    }
  }
  fclose(file_read);
}

void get_str(char *file_name, matrix_t *matr, data_t *data, unsigned int *arr) {
  FILE *file_read = fopen(file_name, "r");
  char str[MAX_LEN_STR] = {0};
  while (fgets(str, sizeof(str), file_read)) {
    if (!strncmp(str, "v ", 2)) {
      fill_matrix_or_array(str, matr, data, arr);
      data->count_row_matrix++;
    }
    if (!strncmp(str, "f ", 2)) fill_matrix_or_array(str, matr, data, arr);
  }
  fclose(file_read);
}

void fill_matrix_or_array(char *str, matrix_t *matr, data_t *data,
                          unsigned int *arr) {
  int count_columns_vertex = 0, count_columns_facets = 0;
  char *token, *rest = NULL;
  for (token = strtok_r(str, " ", &rest); token != NULL;
       token = strtok_r(NULL, " ", &rest)) {
    if (is_num(token[0])) {
      if (!strchr(token, '/')) {
        matr->matrix[data->count_row_matrix][count_columns_vertex] =
            atof(token);
        count_columns_vertex++;
      } else {
        arr[data->count_num_facets + count_columns_facets] = atof(token);
        count_columns_facets++;
      }
    }
  }
  data->count_num_facets += count_columns_facets;
}

void get_coords_facets(matrix_t *matr, data_t *data, const unsigned int *arr1,
                       double *arr2) {
  int currenNum = 0;
  for (unsigned int i = 0; i < data->count_indexes_facets; i++) {
    unsigned int currentStr = arr1[i] - 1;
    for (int k = 0; k < 3; k++) arr2[currenNum++] = matr->matrix[currentStr][k];
  }
}

int is_num(double num) {
  int res = 0;
  if (num >= '0' && num <= '9') res = 1;
  if (num == '.' || num == ',') res = 1;
  if (num == '-') res = 1;
  return res;
}
