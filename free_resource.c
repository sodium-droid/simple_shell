#include "main.h"

/**
 * free_res - frees the used resources, especially a character pointer
 * @lineptr: the character pointer to be freed
 * @n: this variable is reset back to zero
 */
void free_res(char **lineptr, size_t *n)
{
	free(*lineptr);
	*lineptr = NULL;
	*n = 0;
}
