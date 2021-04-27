#include "main.h"
#include "matrix.h"
#include "prompt.h"

#include <limits.h>

#define MATRIX_ID_MAX_LENGTH 25

int main (void)
{
	status_t st;
	static matrix_t **matrix_ids;

	/*	Only prints the main header	*/
	prompt_welcome();

	/*	array to store the matrix entered on the program execution	*/
	matrix_ids = (matrix_t **)calloc(MATRIX_IDS_ARRAY_LENGTH, sizeof(matrix_t));
	for(size_t i = 0; i < MATRIX_IDS_ARRAY_LENGTH; i++)
		matrix_ids[i] = (matrix_t *)calloc(MATRIX_ID_MAX_LENGTH, sizeof(matrix_t));

	/*	The main prompt ask for a matrix interactively and returns a pointer to it	with the values already initialized	*/
	for(size_t i = 0;i < UINT_MAX;i++) {
		if((st = get_matrix(matrix_ids[i], matrix_ids)) != OK) {
			/*	Prompt what do you want to do with the matrix you entered?	*/
			printf("%s", "What do you want to do with the matrix you entered?: ");
			return st;
		}
	}
	return 0;
}
