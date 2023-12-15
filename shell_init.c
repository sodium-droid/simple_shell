#include "main.h"

/**
 * shell_init - takes and execute command line
 * @prog_n: program's name
 * @lineptr_to_update: lineptr variable to store read line buffer
 * @env: list of environment variables
 * Return: 0, if no error, otherwise 1 is returned
 */
int shell_init(char *prog_n, char **lineptr_to_update, char **env)
{
	char *lineptr = NULL, *msg = "#cisfun$ ";
	size_t n = 0;
	int does_exist, num_tokens;
	char *argv[1024];
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
	num_tokens = count_tokens(lineptr);
	tokenize(argv, lineptr);
	if (access(argv[0], F_OK | X_OK) == -1)
	{
		perror(prog_n);
		free_res2(argv, num_tokens, lineptr);
		return (0);
	}
	does_exist = stat(argv[0], &st);
	if (does_exist == -1)
	{
		perror(prog_n);
		free_res2(argv, num_tokens, lineptr);
		return (0);
	}
	get_lineptr(&lineptr, &(*lineptr_to_update));
	if ((execve(argv[0], argv, env) == -1))
	{
		perror(prog_n);
		free_res2(argv, num_tokens, lineptr);
		return (0);
	}
	return (0);
}
