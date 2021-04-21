#include "prompt.h"

status_t prompt_welcome(void)
{
/*	Main loop	*/
	while( 1 ) {
		printf("Welcome to matrix-calculator!\n");
		printf("What do you want to do?\n");
		printf("1.- Load a matrix's values of dimensions X x Y by hand.\n");
		printf("2.- Load a matrix's values with a .txt file.\n");
		printf("3.- Create a random matrix of dimensions X x Y.\n");

		user_input(MAIN_PROMPT);
	}
	return OK;
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
	int i;
	i = getchar();
	
	i = (i - '0');

	return OK;
}
