#ifndef _PROMPT_H
#define _PROMPT_H

#include "matrix.h"
#include "status.h"

typedef enum {
	MAIN_PROMPT
} user_input_t;

status_t prompt_welcome(void);
status_t user_input(user_input_t option);
status_t main_prompt(void);

#endif
