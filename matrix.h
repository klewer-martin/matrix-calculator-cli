#ifndef _MATRIX_STRUCT_H
#define _MATRIX_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

#define MAX_IN_LEN 6

typedef struct {
	size_t rows, columns;
	double **array;
} matrix_t;

void m_print(matrix_t *matrix);
void m_initrand(matrix_t *matrix);
void m_load(matrix_t *matrix);
void m_transpose(matrix_t *matrix, matrix_t *matrix_transpose);

void m_add(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result);
void m_substract(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result);
void m_multiply(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result);
void m_divide(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result);

void m_create(size_t rows, size_t columns, matrix_t *matrix);
void m_destroy(matrix_t *matrix);


void empty_string(char *string, size_t len);

bool m_isSimetric(matrix_t *matrix);

#endif
