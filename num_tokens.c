#include "main.h"

/**
 * _strcpy - copies string values to memory location
 * @dest: the memory address location
 * @src: the string whose values' memory locaton is copied
 *
 * Description: copies the string pointed to by src variable,
 * including the termination null byte(\0), to the the buffer,
 * pointed to by dest
 * Return: the memory location string
 */
char *_strcpy(char *dest, char *src)
{
	int len = (int) strlen(src);
	int i = 0;

	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * count_tokens - counts the number token that can gotten from a string
 * @lineptr: the string from which tokens are extracted
 *
 * Return: the number of token that can be gotten from the string or zero,
 * if none can be gotten from the given string
 */
int count_tokens(char *lineptr)
{
	int n_tokens = 0;
	char *lineptr_cpy = malloc(sizeof(char) * strlen(lineptr));
	char *tokens;

	_strcpy(lineptr_cpy, lineptr);
	tokens = strtok(lineptr_cpy, " \n\t\r");
	while (tokens)
	{
		n_tokens++;
		tokens = strtok(NULL, " \n\t\r");
	}
	free(lineptr_cpy);
	return (n_tokens);
}

/**
 * tokenize - tokenizes (breaks into chunks) a string based on delimiter
 * @argv: array of the each string extracted (tokenized) from the string
 * @lineptr: the string from, which sub-strings are extracted based on
 * the given delimiter
 */
void tokenize(char *argv[], char *lineptr)
{
	char *token = NULL;
	int i;
	char *lineptr_cpy = malloc(sizeof(char) * (strlen(lineptr) + 1));
	char *delim = " \n\t\r";

	lineptr_cpy = _strcpy(lineptr_cpy, lineptr);
	token = strtok(lineptr_cpy, delim);
	i = 0;
	while (token)
	{
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		_strcpy(argv[i], token);
		i++;
		token = strtok(NULL, delim);
		if (token == NULL)
			argv[i] = NULL;
	}
	free(lineptr_cpy);
}
