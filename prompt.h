#ifndef _PROMPT_H
#define _PROMPT_H

#include "matrix.h"
#include "status.h"

#include <unistd.h>

#define MAX_MAIN_PROMPT_CMD 3
#define MAX_ADD_MATRIX	2
#define SIZE_OF_BUFFER 10

/*
#define MAIN_PROMPT_MSG "1. Load a matrix's values of dimensions N x M by hand.\n"\
					"2. Load a matrix's values from a .csv file.\n"\
					"p. Create a random matrix of dimensions N x M.\n"\
					"q  exit\n\nWhat do you want to do?: "
*/

#define MAIN_PROMPT_MSG ""\
	"n. Create new matrix.\n"\
	"p. Print matrix.\n"\
	"a. Add two matrix.\n"\
	"s. Substract two matrix.\n"\
	"m. Multiply two matrix.\n"\
	"d. Divide two matrix.\n"\
	"t. Matrix transpose.\n"\
	"i. Matrix inverse.\n"\
	"q  exit\n\nWhat do you want to do?: "

status_t main_prompt(matrix_t **matrix_ids);
status_t nw(matrix_t **matrix_ids);
status_t load_m_hand(matrix_t *matrix);

#endif
