#include "main.h"
#include "matrix.h"
#include "prompt.h"

#define R 3

int main (void)
{
/*	matrix_t matrix;
	matrix_t matrix2;
	matrix_t matrix_r;

	m_create(R, R, &matrix);
	m_create(R, R, &matrix2);
	m_create(R, R, &matrix_r);

	m_load(N, M, matrix);
	m_print(N, M, matrix);

	putchar('\n');
	
	m_transpose(&matrix, &matrix_transpose);
	m_print(&matrix_transpose);


	m_load(&matrix);
	m_print(&matrix);
	putchar('\n');

	m_load(&matrix2);
	m_print(&matrix2);
	putchar('\n');

	m_multiply(&matrix, &matrix2, &matrix_r);
	m_print(&matrix_r);
	putchar('\n');

	m_destroy(&matrix);
	m_destroy(&matrix2);
	m_destroy(&matrix_r);


	*/
	prompt_welcome();
	return 0;
}
