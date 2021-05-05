#include "prompt.h"

status_t main_prompt(matrix_t **matrix_ids)
{
	status_t st;
	size_t j;
	char *buffer;

	/*	buffer to store the user option	*/
	buffer = (char *)calloc(INPUT_BUFFER_MAX_LENGTH + 1, sizeof(char));

	/*	Prompt the user for an option	*/
	fgets(buffer, INPUT_BUFFER_MAX_LENGTH, stdin);
	if(buffer[0] == '\n') {
		while(buffer[0] == '\n') {
			printf("%s", "What do you want to do?: ");
			fgets(buffer, DIM_BUFFER_MAX_SIZE, stdin);
		}
	}	else if (buffer[0] == 'q') {
		return EXIT_SUCCESS;
	}

	putchar('\n');
	switch(buffer[0]) {
		case 'n': {	printf("Hello world!\n");	} break;
		case 'p':
			{
				empty_string(buffer, DIM_BUFFER_MAX_SIZE);
				printf("Introduce matrix id to print(Default 1): ");
				fgets(buffer, DIM_BUFFER_MAX_SIZE, stdin);

				if(buffer[0] == '\n') {
					j = 1;
				} else {
					j = strtol(buffer, NULL, 10);
				}
				m_print(m_search(j, matrix_ids));
				putchar('\n');
			} break;
		case 'a':
			{
				static size_t prev_id = 1;
				size_t *ids_to_add;
				ids_to_add = (size_t *)calloc(MAX_IN_LEN, sizeof(size_t));

				for(size_t k = 0; k < MAX_ADD_MATRIX; k++) {
					empty_string(buffer, DIM_BUFFER_MAX_SIZE);
					printf("Introduce id of the first matrix to add(Default %lu): ", prev_id);
					fgets(buffer, DIM_BUFFER_MAX_SIZE, stdin);

					if(buffer[0] == '\n') {
						ids_to_add[k] = prev_id++;
						printf("First id to add is: %lu\n", ids_to_add[k]);
					} else {
						ids_to_add[k] = strtol(buffer, NULL, 10);
						printf("First id to add is: %lu\n", ids_to_add[k]);
					}
				}
				if((st = m_add(m_search(ids_to_add[0], matrix_ids), m_search(ids_to_add[1], matrix_ids), matrix_ids[3])) != OK) {
					printf("Error\n");
					return st;
				}
				m_print(matrix_ids[3]);
				putchar('\n');
			} break;
	}

	free(buffer);
	return OK;
}

/*
status_t nw(matrix_t **matrix_ids)
{
	if(matrix_ids == NULL)
		return ERROR_NULL_POINTER;

	status_t st;
	matrix_t matrix;
	size_t j;

	if((st = get_id(matrix->id) != OK)
		return st;
	*/
	/*	Now i contains the ID of the created matrix	*/
/*
	matrix.id = j;
	printf("The id you entered is: %lu\n", matrix.id);
*/
	/*	Now we ask for the dimensions of the matrix	*/
//	m_load_dim(matrix);

	/*	And we create the matrix	*/
//	m_create(matrix->rows, matrix->columns, matrix);
//	putchar('\n');

	/*	Now we ask for the values	*/
/*
	m_load(matrix);

	printf("%s", "The matrix you entered is: \n");
	m_print(matrix);
	putchar('\n');
	return OK;
}


status_t get_id(size_t id)
{
	static size_t prev_id = 1;

	//	Enter the matrix Number(1 .. 128, Default 1):
	printf("Enter the matrix id number (1 .. 128, Default %lu): ", prev_id);

	empty_string(buffer, DIM_BUFFER_MAX_SIZE);
	fgets(buffer, DIM_BUFFER_MAX_SIZE, stdin);

	if(buffer[0] == '\n') {
		j = prev_id++;
	} else {
		j = strtol(buffer, NULL, 10);
	}

	return OK;
}
*/
