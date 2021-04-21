#include "main.h"
#include "matrix.h"
#include "prompt.h"

#define R 3

int main (void)
{
	/*
	matrix_t matrix;
	m_load_dim(&matrix);

	m_create(matrix.rows, matrix.columns, &matrix);

	m_initrand(&matrix);
	m_print(&matrix);
	putchar('\n');

	m_destroy(&matrix);
	*/
	prompt_welcome();

	return 0;
}
