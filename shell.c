#include "main.h"

/**
 * main - entry to the simple shell program
 * @ac: argument's counter
 * @av: argument's vector
 * Return: 0, if no error, otherwise 1.
 */
int main(int ac, char **av)
{
	int status, does_exist, num_tokens;
	pid_t ps;
	size_t n = 0;
	char *lineptr = NULL, *argv[512], *msg = "#cisfun$ ";
	struct stat st;
	char newline = '\n', *path = _getenv("PATH"), command_path;
	struct stat st;

	while (1)
	{
		write(1, msg, _strlen(msg));
		getline(&lineptr, &n, stdin);
	       	if (*lineptr == EOF)
		{
			free_res(&lineptr, &n);
			exit(96);
		}
		if (_strcmp(lineptr, "exit") == 0)
		{
			free_res(&lineptr, &n);
			break;
		}
		if (*((int *) lineptr) == 10)
		{
			free_res(&lineptr, &n);
			continue;
		}
		num_tokens = count_tokens(lineptr);
		tokenize(argv, lineptr);
		does_exist = stat(argv[0], &st);
		if (does_exist == -1)
		{
			
		}
		else

	}
	return (0);
}
