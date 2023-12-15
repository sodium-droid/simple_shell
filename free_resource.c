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
 * free_res2 - frees both a character pointer and pointers' array
 * @argv: pointers' array to be freed
 * @num_tokens: the number of array elements to be freed
 * @lineptr: the character pointer to be freed
 */
void free_res2(char *argv[], int num_tokens, char *lineptr)
{
	int i;

	for (i = 0; i < num_tokens; i++)
		free(argv[i]);
	free(lineptr);
}
