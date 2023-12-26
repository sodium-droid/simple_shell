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
 * to_int - converts a string into a number
 * @str: the string from which number is extracted and converted to integer
 *
 * Return: the integer type of the converted number
 */
int to_int(char *str)
{
	int i = 0, j = 0, num = 0, temp, times, power_of, str_len = _strlen(str) - 1;

	while (j < str_len)
	{
		temp = (int)str[i] - 48;
		if (str_len == 1)
			temp *= 1;
		else if (str_len == 2)
			temp *= 10;
		else if (str_len > 2)
		{
			times = str_len;
			power_of = 1;
			while (times)
			{
				if (times >= 2)
					power_of *= 10;
				times--;
			}
			temp *= power_of;
		}
		num += temp;
		str_len--;
		i++;
	}
	return (num);
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

/**
 * exit_with_status - exits a program, using a given exit's status code
 * @lineptr: the command line that contains the status code
 */
void exit_with_status(char *lineptr)
{
	char *cmd[3];
	int exit_code;

	tokenize(cmd, lineptr);
	if (cmd[1] != NULL)
	{
		exit_code = to_int(cmd[1]);
		free(lineptr);
		exit(exit_code);
	}
	else
	{
		free(lineptr);
		exit(96);
	}
}


/**
 * is_exit - checks if the commandline is exit command
 * @lineptr: the texts to be checked for exit
 * @exit_keyword: the exit word to be looked up from lineptr
 *
 * Return: 1, if exit is found, otherwise 0 is returned
*/
int is_exit(char *lineptr, char *exit_keyword)
{
	int i, result = 0, exit_keyword_len = _strlen(exit_keyword);

	for (i = 0; i < exit_keyword_len; i++)
	{
		if ((int)exit_keyword[i] == (int)lineptr[i])
			result = 1;
		else
			result = 0;
	}
	return (result);
}

