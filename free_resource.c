#include "main.h"

void free_res(char **lineptr, size_t *n)
{
	free(*lineptr);
	*lineptr = NULL;
	*n = 0;
}
