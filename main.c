#include "main.h"
#include "matrix.h"
#include "prompt.h"

void alloc_ids(matrix_t **matrix_ids);
void free_ids(matrix_t **matrix_ids);

int main (void)
{
	status_t st;
	static matrix_t **matrix_ids;

	matrix_ids = (matrix_t **)calloc(MATRIX_IDS_ARRAY_LENGTH, sizeof(matrix_t));
	alloc_ids(matrix_ids);

	printf("%s%s", "Welcome to matrix-calculator!\n\n", MAIN_PROMPT_MSG);

	while((st = main_prompt(matrix_ids)) != OK) {
		if(st != OK) {
			if(st == EXIT_SUCCESS)
				return OK;

			free_ids(matrix_ids);
			return st;
		}
	}

	free_ids(matrix_ids);
	return 0;
}

void alloc_ids(matrix_t **matrix_ids)
{
	for(size_t i = 0; i < MATRIX_IDS_ARRAY_LENGTH; i++)
		matrix_ids[i] = (matrix_t *)calloc(MATRIX_ID_MAX_LENGTH, sizeof(matrix_t));
}

void free_ids(matrix_t **matrix_ids)
{
	for(size_t i = (MATRIX_IDS_ARRAY_LENGTH - 1); i > 0; i--)
		free(matrix_ids[i]);

	free(matrix_ids);
}
