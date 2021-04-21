#ifndef _STATUS_H
#define _STATUS_H

typedef enum {
	OK,
	ERROR_MATRIX_DIMENSION,
	ERROR_NO_USER_INPUT,
	ERROR_MAX_CMD_PROMPT,
	ERROR_ALLOCATING_MEMORY,
	ERROR_NULL_POINTER
} status_t;

#endif