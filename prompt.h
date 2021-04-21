#ifndef _PROMPT_H
#define _PROMPT_H

#include "matrix.h"
#include "status.h"

#include <unistd.h>

#define MAX_MAIN_PROMPT_CMD 3
#define SIZE_OF_BUFFER 10

typedef enum {
	MAIN_PROMPT
} user_input_t;

void prompt_welcome(void);
status_t user_input(user_input_t option);
status_t main_prompt(void);
status_t load_m_hand(matrix_t *matrix);

#endif
