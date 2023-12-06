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
	char *cmd;
	struct stat st;
	int does_exist;
	char *argv[2];

	printf("#cisfun$ ");
	getline(&lineptr, &n, stdin);
	cmd = strtok(lineptr, "\n");
	does_exist = stat(cmd, &st);
	if (does_exist == 0)
	{
		argv[0] = cmd;
		argv[1] = NULL;
		execve(argv[0], argv, environ);
	}
	else
	{
		printf("%s: No such file or directory\n", prog_n);
		return (1);
	}
	free(lineptr);
	return (0);
}
