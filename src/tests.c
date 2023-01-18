#include <check.h>

#include "3dviewer.h"
#include "matrix.h"

START_TEST(create_matrix_1) {
  matrix_t A = create_matrix(1, 1);
  ck_assert_double_eq(A.matrix[0][0], 0.0);
  remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_2) {
  matrix_t A = create_matrix(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 0;
    }
  }
  matrix_t B = create_matrix(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(A.matrix[i][j], B.matrix[i][j]);
    }
  }
  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(move_matrix_3) {
  matrix_t A = create_matrix(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 1;
    }
  }
  move_matrix(&A, 3, 3, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(A.matrix[i][j], 4);
    }
  }
  remove_matrix(&A);
}
END_TEST

START_TEST(move_matrix_4) {
  matrix_t A = create_matrix(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 5;
    }
  }
  move_matrix(&A, -3, -3, -3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(A.matrix[i][j], 2);
    }
  }
  remove_matrix(&A);
}
END_TEST

START_TEST(move_matrix_5) {
  matrix_t A = create_matrix(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 5;
    }
  }
  move_matrix(&A, 0, 0, 0);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(A.matrix[i][j], 5);
    }
  }
  remove_matrix(&A);
}
END_TEST

START_TEST(rotate_x_6) {
  matrix_t A = create_matrix(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 5;
    }
  }
  rotate_x(&A, 50);
  matrix_t B = create_matrix(2, 3);
  B.matrix[0][0] = 5;
  B.matrix[0][1] = -0.6162842;
  B.matrix[0][2] = 7.0441603;
  B.matrix[1][0] = 5;
  B.matrix[1][1] = -0.6162842;
  B.matrix[1][2] = 7.0441603;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(A.matrix[i][j] - B.matrix[i][j] < 1e-7, 1);
    }
  }
  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(rotate_x_7) {
  matrix_t A = create_matrix(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 5;
    }
  }
  rotate_x(&A, 0);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(A.matrix[i][j], 5);
    }
  }
  remove_matrix(&A);
}
END_TEST

START_TEST(rotate_y_8) {
  matrix_t A = create_matrix(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 5;
    }
  }
  rotate_y(&A, 50);
  matrix_t B = create_matrix(2, 3);
  B.matrix[0][0] = -0.6162842;
  B.matrix[0][1] = 5;
  B.matrix[0][2] = 7.0441603;
  B.matrix[1][0] = -0.6162842;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 7.0441603;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(A.matrix[i][j] - B.matrix[i][j] < 1e-7, 1);
    }
  }
  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(rotate_y_9) {
  matrix_t A = create_matrix(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 5;
    }
  }
  rotate_y(&A, 0);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(A.matrix[i][j], 5);
    }
  }
  remove_matrix(&A);
}
END_TEST

START_TEST(rotate_z_10) {
  matrix_t A = create_matrix(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 5;
    }
  }
  rotate_z(&A, 50);
  matrix_t B = create_matrix(2, 3);
  B.matrix[0][0] = -0.6162842;
  B.matrix[0][1] = 7.0441603;
  B.matrix[0][2] = 5;
  B.matrix[1][0] = -0.6162842;
  B.matrix[1][1] = 7.0441603;
  B.matrix[1][2] = 5;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(A.matrix[i][j] - B.matrix[i][j] < 1e-7, 1);
    }
  }
  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(rotate_z_11) {
  matrix_t A = create_matrix(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 5;
    }
  }
  rotate_z(&A, 0);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(A.matrix[i][j], 5);
    }
  }
  remove_matrix(&A);
}
END_TEST

START_TEST(scale_matrix_12) {
  matrix_t A = create_matrix(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 2;
    }
  }
  scale_matrix(&A, 5);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(A.matrix[i][j], 10);
    }
  }
  remove_matrix(&A);
}
END_TEST

START_TEST(scale_matrix_13) {
  matrix_t A = create_matrix(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 5;
    }
  }
  scale_matrix(&A, -2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(A.matrix[i][j], 2.5);
    }
  }
  remove_matrix(&A);
}
END_TEST

START_TEST(scale_matrix_14) {
  matrix_t A = create_matrix(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 5;
    }
  }
  scale_matrix(&A, 0);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(A.matrix[i][j], 5);
    }
  }
  remove_matrix(&A);
}
END_TEST

START_TEST(is_num_15) {
  ck_assert_int_eq(is_num('1'), 1);
  ck_assert_int_eq(is_num('.'), 1);
  ck_assert_int_eq(is_num(','), 1);
  ck_assert_int_eq(is_num('-'), 1);
  ck_assert_int_eq(is_num('a'), 0);
  ck_assert_int_eq(is_num('*'), 0);
}
END_TEST

START_TEST(get_file_info_16) {
  char file_name[] = "../examples/cube.obj";
  data_t file_info = {0, 0, 0, 0, 0};
  FILE *fileRead = fopen(file_name, "r");
  get_file_info(fileRead, &file_info);
  ck_assert_int_eq(file_info.count_rows_vertexes, 8);
  ck_assert_int_eq(file_info.count_rows_facets, 12);
  ck_assert_int_eq(file_info.count_indexes_facets, 36);
}
END_TEST

START_TEST(get_str_17) {
  char file_name[] = "../examples/cube.obj";
  data_t file_info = {0, 0, 0, 0, 0};
  FILE *fileRead = fopen(file_name, "r");
  get_file_info(fileRead, &file_info);
  matrix_t matrVertexes = create_matrix(file_info.count_rows_vertexes, 3);
  unsigned int *arrIndexesFacets = (unsigned int *)calloc(
      file_info.count_indexes_facets, sizeof(unsigned int));
  get_str(file_name, &matrVertexes, &file_info, arrIndexesFacets);
  ck_assert_int_eq(file_info.count_num_facets, 36);
  ck_assert_int_eq(file_info.count_row_matrix, 8);
  remove_matrix(&matrVertexes);
  free(arrIndexesFacets);
}
END_TEST

START_TEST(fill_matrix_or_array_18) {
  char file_name[] = "../examples/cube.obj";
  data_t file_info = {0, 0, 0, 0, 0};
  FILE *fileRead = fopen(file_name, "r");
  get_file_info(fileRead, &file_info);
  matrix_t matrVertexes = create_matrix(file_info.count_rows_vertexes, 3);
  unsigned int *arrIndexesFacets = (unsigned int *)calloc(
      file_info.count_indexes_facets, sizeof(unsigned int));
  get_str(file_name, &matrVertexes, &file_info, arrIndexesFacets);
  matrix_t A = create_matrix(8, 3);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = -1;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -1;
  A.matrix[2][1] = -1;
  A.matrix[2][2] = 1;
  A.matrix[3][0] = -1;
  A.matrix[3][1] = -1;
  A.matrix[3][2] = -1;
  A.matrix[4][0] = 1;
  A.matrix[4][1] = 1;
  A.matrix[4][2] = -1;
  A.matrix[5][0] = 0.9999990;
  A.matrix[5][1] = 1;
  A.matrix[5][2] = 1.000001;
  A.matrix[6][0] = -1;
  A.matrix[6][1] = 1;
  A.matrix[6][2] = 1;
  A.matrix[7][0] = -1;
  A.matrix[7][1] = 1;
  A.matrix[7][2] = -1;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(matrVertexes.matrix[i][j] - A.matrix[i][j] < 1e-7, 1);
    }
  }
  remove_matrix(&matrVertexes);
  remove_matrix(&A);
  free(arrIndexesFacets);
}
END_TEST

START_TEST(fill_matrix_or_array_19) {
  char file_name[] = "../examples/cube.obj";
  data_t file_info = {0, 0, 0, 0, 0};
  FILE *fileRead = fopen(file_name, "r");
  get_file_info(fileRead, &file_info);
  matrix_t matrVertexes = create_matrix(file_info.count_rows_vertexes, 3);
  unsigned int *arrIndexesFacets = (unsigned int *)calloc(
      file_info.count_indexes_facets, sizeof(unsigned int));
  get_str(file_name, &matrVertexes, &file_info, arrIndexesFacets);
  unsigned int A[] = {5, 1, 4, 5, 4, 8, 3, 7, 8, 3, 8, 4, 2, 6, 3, 6, 7, 3,
                      1, 5, 2, 5, 6, 2, 5, 8, 6, 8, 7, 6, 1, 2, 3, 1, 3, 4};
  for (int i = 0; i < (int)file_info.count_indexes_facets; i++)
    ck_assert_int_eq(arrIndexesFacets[i], A[i]);
  remove_matrix(&matrVertexes);
  free(arrIndexesFacets);
}
END_TEST

START_TEST(get_coords_facets_20) {
  char file_name[] = "../examples/cube.obj";
  data_t file_info = {0, 0, 0, 0, 0};
  FILE *fileRead = fopen(file_name, "r");
  get_file_info(fileRead, &file_info);
  matrix_t matrVertexes = create_matrix(file_info.count_rows_vertexes, 3);
  unsigned int *arrIndexesFacets = (unsigned int *)calloc(
      file_info.count_indexes_facets, sizeof(unsigned int));
  double *arr_coords_facets =
      (double *)calloc(file_info.count_indexes_facets * 3, sizeof(double));
  get_str(file_name, &matrVertexes, &file_info, arrIndexesFacets);
  get_coords_facets(&matrVertexes, &file_info, arrIndexesFacets,
                    arr_coords_facets);
  const double A[] = {
      1,        1,  -1,       1,        -1, -1,       -1,       -1, -1,
      1,        1,  -1,       -1,       -1, -1,       -1,       1,  -1,
      -1,       -1, 1,        -1,       1,  1,        -1,       1,  -1,
      -1,       -1, 1,        -1,       1,  -1,       -1,       -1, -1,
      1,        -1, 1,        0.999999, 1,  1.000001, -1,       -1, 1,
      0.999999, 1,  1.000001, -1,       1,  1,        -1,       -1, 1,
      1,        -1, -1,       1,        1,  -1,       1,        -1, 1,
      1,        1,  -1,       0.999999, 1,  1.000001, 1,        -1, 1,
      1,        1,  -1,       -1,       1,  -1,       0.999999, 1,  1.000001,
      -1,       1,  -1,       -1,       1,  1,        0.999999, 1,  1.000001,
      1,        -1, -1,       1,        -1, 1,        -1,       -1, 1,
      1,        -1, -1,       -1,       -1, 1,        -1,       -1, -1};
  for (int i = 0; i < (int)file_info.count_indexes_facets * 3; i++)
    ck_assert_double_eq(arr_coords_facets[i] - A[i] < 1e-7, 1);
  remove_matrix(&matrVertexes);
  free(arrIndexesFacets);
  free(arr_coords_facets);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, create_matrix_1);
  tcase_add_test(tc1_1, create_matrix_2);
  tcase_add_test(tc1_1, move_matrix_3);
  tcase_add_test(tc1_1, move_matrix_4);
  tcase_add_test(tc1_1, move_matrix_5);
  tcase_add_test(tc1_1, rotate_x_6);
  tcase_add_test(tc1_1, rotate_x_7);
  tcase_add_test(tc1_1, rotate_y_8);
  tcase_add_test(tc1_1, rotate_y_9);
  tcase_add_test(tc1_1, rotate_z_10);
  tcase_add_test(tc1_1, rotate_z_11);
  tcase_add_test(tc1_1, scale_matrix_12);
  tcase_add_test(tc1_1, scale_matrix_13);
  tcase_add_test(tc1_1, scale_matrix_14);
  tcase_add_test(tc1_1, is_num_15);
  tcase_add_test(tc1_1, get_file_info_16);
  tcase_add_test(tc1_1, get_str_17);
  tcase_add_test(tc1_1, fill_matrix_or_array_18);
  tcase_add_test(tc1_1, fill_matrix_or_array_19);
  tcase_add_test(tc1_1, get_coords_facets_20);
  srunner_run_all(sr, CK_VERBOSE);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
