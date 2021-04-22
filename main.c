#include "main.h"
#include "matrix.h"
#include "prompt.h"

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
	status_t st;

	prompt_welcome();
	if((st = main_prompt()) != OK)
		return st;

	return 0;
}
