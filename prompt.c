#include "prompt.h"

void prompt_welcome(void)
{
	printf("%s", "Welcome to matrix-calculator!\n\n");
	/*
	printf("Welcome to matrix-calculator!\n\n1.- Load a matrix's values of dimensions N x M by hand.\n2.- Load a matrix's values with a .txt file.\n3.- Create a random matrix of dimensions N x M.\n\nWhat do you want to do?: ");
	*/
}

status_t user_input(user_input_t option)
{
	switch (option) {
		case MAIN_PROMPT:
			break;
		
		default: return ERROR_NO_USER_INPUT;
	}
	return OK;
}

status_t get_matrix(matrix_t *matrix)
{
	printf("1.- Load a matrix's values of dimensions N x M by hand.\n2.- Load a matrix's values with a .txt file.\n3.- Create a random matrix of dimensions N x M.\nq - exit\n\nWhat do you want to do?: ");
	char *buffer;
	size_t i;

	buffer = (char *)malloc(DIM_BUFFER_MAX_SIZE * sizeof(char));
	if(buffer == NULL) return ERROR_ALLOCATING_MEMORY;

	empty_string(buffer, DIM_BUFFER_MAX_SIZE);

	fgets(buffer, DIM_BUFFER_MAX_SIZE, stdin);
	if(buffer[0] == '\n') {
		while(buffer[0] == '\n') {
			printf("%s", "What do you want to do?: ");
			fgets(buffer, DIM_BUFFER_MAX_SIZE, stdin);
		}
	} else if (buffer[0] == 'q') {
		exit(0);
	}


	i = strtol(buffer, NULL, 10);
	if((i < 1) || (i > MAX_MAIN_PROMPT_CMD))
		return ERROR_MAX_MAIN_PROMPT_REACHED;

	empty_string(buffer, DIM_BUFFER_MAX_SIZE);

	putchar('\n');
	switch(i) {
		case 1:
			{
				/*	Enter the matrix Number(1 .. 128, Default 1):	*/
				printf("%s", "Enter the matrix Number (1 .. 128, Default 1): ");

				fgets(buffer, DIM_BUFFER_MAX_SIZE, stdin);
				if(buffer[0] == '\n') {
					i = 1;
				} else {
					i = strtol(buffer, NULL, 10);
				}

				/*	Now i contains the ID of the created matrix	*/
				matrix->id = i;
				printf("The id you entered is: %lu\n", matrix->id);

				/*	Now we ask for the dimensions of the matrix	*/
				m_load_dim(matrix);

				/*	And we create the matrix	*/
				m_create(matrix->rows, matrix->columns, matrix);

				putchar('\n');
				m_load(matrix);
				printf("%s", "The matrix you entered is: \n");
				m_print(matrix);
				putchar('\n');
		}
	}

	free(buffer);
	return OK;
}
