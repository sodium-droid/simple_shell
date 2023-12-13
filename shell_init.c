#include "main.h"

/**
 * shell_init - takes and execute command line
 * @prog_n: program's name
 * @lineptr_to_update: lineptr variable to store read line buffer
 * Return: 0, if no error, otherwise 1 is returned
 */
int shell_init(char *prog_n, char **lineptr_to_update)
{
	char *lineptr = NULL, *msg = "#cisfun$ ";
	size_t n = 0;
	int does_exist;
	char *argv[2];
	struct stat st;

	write(0, msg, 10);
	if (getline(&lineptr, &n, stdin) == -1)
	{
		free_res(&lineptr, &n);
		return (96);
	}
	else if (*((int *)lineptr) == 10)
	{
		free_res(&lineptr, &n);
		return (0);
	}
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
	get_lineptr(&lineptr, &(*lineptr_to_update));
	if ((execve(argv[0], argv, environ) == -1))
		perror(prog_n);
	return (0);
}
