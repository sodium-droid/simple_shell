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

/**
 * get_lineptr - gets the address of the lineptr variable
 * @lineptr: the src address to be obtained
 * @lineptr_add: the destination address
 */
void get_lineptr(char **lineptr, char **lineptr_add)
{
	*lineptr_add = &(**lineptr);
}
