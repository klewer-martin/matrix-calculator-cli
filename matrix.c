#include "matrix.h"

void m_print(matrix_t *matrix)
{
	for(size_t i = 0; i < matrix->rows; i++) {
		putchar('(');
		putchar(' ');
		for(size_t j = 0; j < matrix->columns; j++) {
			printf("%10f ", matrix->array[i][j]);
		}
		putchar(')');
		putchar('\n');
	}
}

void m_initrand(matrix_t *matrix)
{
	srand((unsigned int)time(NULL));
	
	for(size_t i = 0; i < matrix->rows; i++) {
		for(size_t j = 0; j < matrix->columns; j++) {
			matrix->array[i][j] = ((double)rand()/(double)(RAND_MAX)) * 20;
		}
	}
}

void m_load(matrix_t *matrix)
{
	char buf[20];
	int aux;
	for(size_t i = 0; i < matrix->rows; i++) {
		for(size_t j = 0; j < matrix->columns; j++) {
			empty_string(buf, 20);
			for(size_t k = 0; ((aux = getchar()) != '\n') && k < MAX_IN_LEN; k++)
				if(isdigit(aux) || aux == '.')
					buf[k] = aux;
			
			matrix->array[i][j] = strtod(buf, NULL);
		}
	}
}

void m_transpose(matrix_t *matrix, matrix_t *matrix_transpose)
{
	for(size_t i = 0; i < matrix->rows; i++) {
		for(size_t j = 0; j < matrix->columns; j++)
			matrix_transpose->array[j][i] = matrix->array[i][j];

	}
}

void m_add(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result)
{
	/*	This operation can be only performed if both matrix are squared and has the same dimension*/
	if((matrixA->rows != matrixB->rows) || (matrixA->columns != matrixB->columns))
		return;

	for(size_t i = 0; i < result->rows; i++) {
		for(size_t j = 0; j < result->columns; j++) {
			result->array[i][j] = matrixA->array[i][j] + matrixB->array[i][j];

		}	
	}
}

void m_substract(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result)
{
	/*	This operation can be only performed if both matrix are squared and has the same dimension*/
	if((matrixA->rows != matrixB->rows) || (matrixA->columns != matrixB->columns))
		return;

	for(size_t i = 0; i < result->rows; i++) {
		for(size_t j = 0; j < result->columns; j++) {
			result->array[i][j] = matrixA->array[i][j] - matrixB->array[i][j];

		}	
	}
}

void m_multiply(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result)
{
	if(matrixA->columns != matrixB->rows)
		return;

	double aux;
	for(size_t i = 0; i < matrixA->rows; i++) {
		for(size_t j = 0; j < matrixB->columns; j++) {
			for(size_t k = aux = 0; k < matrixA->columns; k++)
				aux += ((matrixA->array[i][k])*(matrixB->array[k][j]));
			
			result->array[i][j] = aux;
		}	
	}
}

void m_divide(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result)
{
	if(matrixA->columns != matrixB->rows)
		return;

	double aux;
	for(size_t i = 0; i < matrixA->rows; i++) {
		for(size_t j = 0; j < matrixB->columns; j++) {
			for(size_t k = aux = 0; k < matrixA->columns; k++)
				aux += ((matrixA->array[i][k]) / (matrixB->array[k][j]));
			
			result->array[i][j] = aux;
		}	
	}
}

void m_create(size_t rows, size_t columns, matrix_t *matrix)
{
	matrix->rows = rows;
	matrix->columns = columns;

	matrix->array = (double **)malloc((rows) * sizeof(double));

	for (size_t i = 0; i < rows; i++)
		 matrix->array[i] = (double *)malloc(columns * sizeof(double));
}

void m_destroy(matrix_t *matrix)
{
	for (size_t i = 0; i < matrix->rows; i++)
		 free(matrix->array[i]);

	free(matrix->array);
}

bool m_isSimetric(matrix_t *matrix)
{
	matrix_t matrix_transpose;
	m_create(matrix->columns, matrix->rows, &matrix_transpose);
	m_transpose(matrix, &matrix_transpose);

	size_t aux = 0;
	for(size_t i = 0; i < matrix->rows; i++)
		for(size_t j = 0; j < matrix->columns; j++)
			if(matrix->array[i][j] == matrix_transpose.array[i][j])
				aux++;

	//if(aux == (r * c))
	//	return true;

	//return false;
	return true * (aux == (matrix->rows * matrix->columns)) + false * (aux != (matrix->rows * matrix->columns));
}

void empty_string(char *string, size_t len)
{
	if(string == NULL) return;

	for(size_t i = 0; i < len; i++)
		string[i] = '\0';
}
