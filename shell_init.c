#include "main.h"

/**
 * shell_init - takes and execute command line
 * @prog_n: program's name
 * Return: 0, if no error, otherwise 1 is returned
 */
int shell_init(char *prog_n)
{
	size_t n = 0;
	char *lineptr = NULL;
	char *argv[2];
	char *msg = "#cisfun$ ";
	struct stat st;
	int does_exist;

	write(0, msg, 10);
	if (getline(&lineptr, &n, stdin) == EOF)
	{
		free_res(&lineptr, &n);
		return (96);
	}
	if (*((int *)lineptr) == 10)
		return (0);
	argv[0] = strtok(lineptr, "\n");
	argv[1] = NULL;
	does_exist = stat(argv[0], &st);
	if (does_exist == -1)
	{
		errno = ENOENT;
		perror(prog_n);
		free_res(&lineptr, &n);
		return (0);
	}
	if ((execve(argv[0], argv, environ) == -1))
	{
		perror(prog_n);
		free_res(&lineptr, &n);
		return (0);
	}
	free_res(&lineptr, &n);
	return (0);
}

