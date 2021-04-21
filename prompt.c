#include "prompt.h"

void prompt_welcome(void)
{
	printf("Welcome to matrix-calculator!\n");
	printf("What do you want to do?\n");
	printf("1.- Load a matrix's values of dimensions N x M by hand.\n");
	printf("2.- Load a matrix's values with a .txt file.\n");
	printf("3.- Create a random matrix of dimensions N x M.\n");
}

status_t user_input(user_input_t option)
{
	switch (option) {
		case MAIN_PROMPT:
			main_prompt();
			break;
		
		default: return ERROR_NO_USER_INPUT;
	}
	return OK;
}

status_t main_prompt(void)
{
	char *buffer;
	size_t i;

	buffer = (char *)malloc(DIM_BUFFER_MAX_SIZE * sizeof(char));
	if(buffer == NULL) return ERROR_ALLOCATING_MEMORY;

	empty_string(buffer, DIM_BUFFER_MAX_SIZE);

	fgets(buffer, DIM_BUFFER_MAX_SIZE, stdin);
	i = strtol(buffer, NULL, 10);
	if((i < 1) || (i > MAX_MAIN_PROMPT_CMD))
		return ERROR_MAX_MAIN_PROMPT_REACHED;

	putchar('\n');
	switch(i) {
		case 1:
			{
				matrix_t matrix;
				m_load_dim(&matrix);

				m_create(matrix.rows, matrix.columns, &matrix);

				putchar('\n');
				m_load(&matrix);
				printf("%s", "The matrix you entered is:\n");
				m_print(&matrix);
				m_destroy(&matrix);
		}
	}
	return OK;
}
