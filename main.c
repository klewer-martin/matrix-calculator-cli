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

	/*	Only prints the main header	*/
	prompt_welcome();

	matrix_t matrix;

	/*	The main prompt ask for a matrix interactively and returns a pointer to it	with the values already initialized	*/
	while( 1 ) {
		if((st = get_matrix(&matrix)) != OK) {
			/*	Prompt what do you want to do with the matrix you entered?	*/
			printf("%s", "What do you want to do with the matrix you entered?: ");
			return st;
		}
	}
	return 0;
}
