#ifndef _MATRIX_STRUCT_H
#define _MATRIX_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

#include "status.h"

#define MAX_IN_LEN 6
#define DIM_BUFFER_MAX_SIZE 6

typedef struct {
	size_t rows, columns;
	double **array;
	size_t id;
} matrix_t;

status_t m_print(matrix_t *matrix);
status_t m_initrand(matrix_t *matrix);
status_t m_load(matrix_t *matrix);
status_t m_load_dim(matrix_t *matrix);
status_t m_transpose(matrix_t *matrix, matrix_t *matrix_transpose);
status_t m_add(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result);
status_t m_substract(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result);
status_t m_multiply(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result);
status_t m_divide(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result);
status_t m_create(size_t rows, size_t columns, matrix_t *matrix);
status_t m_destroy(matrix_t *matrix);


status_t empty_string(char *string, size_t len);

bool m_isSimetric(matrix_t *matrix);

#endif
