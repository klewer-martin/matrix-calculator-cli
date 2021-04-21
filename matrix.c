#include "matrix.h"

status_t m_print(matrix_t *matrix)
{
	if(matrix == NULL) return ERROR_NULL_POINTER;

	for(size_t i = 0; i < matrix->rows; i++) {
		putchar('(');
		putchar(' ');
		for(size_t j = 0; j < matrix->columns; j++) {
			printf("%10f ", matrix->array[i][j]);
		}
		putchar(')');
		putchar('\n');
	}
	return OK;
}

status_t m_initrand(matrix_t *matrix)
{
	if(matrix == NULL) return ERROR_NULL_POINTER;

	srand((unsigned int)time(NULL));
	for(size_t i = 0; i < matrix->rows; i++) {
		for(size_t j = 0; j < matrix->columns; j++) {
			matrix->array[i][j] = ((double)rand()/(double)(RAND_MAX)) * 20;
		}
	}
	return OK;
}

status_t m_load(matrix_t *matrix)
{
	if(matrix == NULL) return ERROR_NULL_POINTER;

	printf("%s", "Matrix of dimension N x M:\n\
			( 00 01 .. 0N )\n\
			( 10 01 .. 1N )\n\
			( .. .. .. .. )\n\
			( M0 M1 .. MN )\n");
	char buf[MAX_IN_LEN];
	int aux;
	for(size_t i = 0; i < matrix->rows; i++) {
		for(size_t j = 0; j < matrix->columns; j++) {
			empty_string(buf, MAX_IN_LEN);
			printf("Enter value %ld%ld of the matrix.\n", i, j);
			for(size_t k = 0; ((aux = getchar()) != '\n') && k < MAX_IN_LEN; k++)
				if(isdigit(aux) || (aux == '.') || (aux == '-'))
					buf[k] = aux;
			
			matrix->array[i][j] = strtod(buf, NULL);
		}
	}
	return OK;
}

status_t m_load_dim(matrix_t *matrix)
{
	if(matrix == NULL) return ERROR_NULL_POINTER;

	char *buffer;
	buffer = (char *)malloc(DIM_BUFFER_MAX_SIZE * sizeof(char));
	if(buffer == NULL) return ERROR_ALLOCATING_MEMORY;

	empty_string(buffer, DIM_BUFFER_MAX_SIZE);

	printf("%s", "Enter no. of rows: \n");
	fgets(buffer, DIM_BUFFER_MAX_SIZE, stdin);
	matrix->rows = strtol(buffer, NULL, 10);

	empty_string(buffer, DIM_BUFFER_MAX_SIZE);

	printf("%s", "Enter no. of columns: \n");
	fgets(buffer, DIM_BUFFER_MAX_SIZE, stdin);
	matrix->columns = strtol(buffer, NULL, 10);

	free(buffer);
	return OK;
}

status_t m_transpose(matrix_t *matrix, matrix_t *matrix_transpose)
{
	if((matrix == NULL) || (matrix_transpose == NULL))
		return ERROR_NULL_POINTER;

	for(size_t i = 0; i < matrix->rows; i++) {
		for(size_t j = 0; j < matrix->columns; j++)
			matrix_transpose->array[j][i] = matrix->array[i][j];

	}
	return OK;
}

status_t m_add(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result)
{
	if((matrixA == NULL) || (matrixB == NULL) || (result == NULL))
		return ERROR_NULL_POINTER;
	/*	This operation can be only performed if both matrix are squared and has the same dimension*/
	if((matrixA->rows != matrixB->rows) || (matrixA->columns != matrixB->columns))
		return ERROR_MATRIX_DIMENSION;

	for(size_t i = 0; i < result->rows; i++) {
		for(size_t j = 0; j < result->columns; j++) {
			result->array[i][j] = matrixA->array[i][j] + matrixB->array[i][j];

		}	
	}
	return OK;
}

status_t m_substract(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result)
{
	if((matrixA == NULL) || (matrixB == NULL) || (result == NULL))
		return ERROR_NULL_POINTER;
	/*	This operation can be only performed if both matrix are squared and has the same dimension*/
	else if((matrixA->rows != matrixB->rows) || (matrixA->columns != matrixB->columns))
		return ERROR_MATRIX_DIMENSION;

	for(size_t i = 0; i < result->rows; i++) {
		for(size_t j = 0; j < result->columns; j++) {
			result->array[i][j] = matrixA->array[i][j] - matrixB->array[i][j];

		}	
	}
	return OK;
}

status_t m_multiply(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result)
{
	if((matrixA == NULL) || (matrixB == NULL) || (result == NULL))
		return ERROR_NULL_POINTER;
	else if(matrixA->columns != matrixB->rows)
		return ERROR_MATRIX_DIMENSION;

	double aux;
	for(size_t i = 0; i < matrixA->rows; i++) {
		for(size_t j = 0; j < matrixB->columns; j++) {
			for(size_t k = aux = 0; k < matrixA->columns; k++)
				aux += ((matrixA->array[i][k])*(matrixB->array[k][j]));
			
			result->array[i][j] = aux;
		}	
	}
	return OK;
}

status_t m_divide(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result)
{
	if((matrixA == NULL) || (matrixB == NULL) || (result == NULL))
		return ERROR_NULL_POINTER;
	else if(matrixA->columns != matrixB->rows)
		return ERROR_MATRIX_DIMENSION;

	double aux;
	for(size_t i = 0; i < matrixA->rows; i++) {
		for(size_t j = 0; j < matrixB->columns; j++) {
			for(size_t k = aux = 0; k < matrixA->columns; k++)
				aux += ((matrixA->array[i][k]) / (matrixB->array[k][j]));
			
			result->array[i][j] = aux;
		}	
	}
	return OK;
}

status_t m_create(size_t rows, size_t columns, matrix_t *matrix)
{
	if(matrix == NULL) return ERROR_NULL_POINTER;

	matrix->rows = rows;
	matrix->columns = columns;

	matrix->array = (double **)malloc((rows) * sizeof(double));

	for (size_t i = 0; i < rows; i++)
		 matrix->array[i] = (double *)malloc(columns * sizeof(double));

	return OK;
}

status_t m_destroy(matrix_t *matrix)
{
	if(matrix == NULL) return ERROR_NULL_POINTER;

	for (size_t i = 0; i < matrix->rows; i++)
		 free(matrix->array[i]);

	free(matrix->array);
	return OK;
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

status_t empty_string(char *string, size_t len)
{
	if(string == NULL) return ERROR_NULL_POINTER;

	for(size_t i = 0; i < len; i++)
		string[i] = '\0';

	return OK;
}
