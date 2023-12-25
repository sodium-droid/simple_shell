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
	int num_tokens;
	char *argv[1024], newln = '\n';

	write(0, msg, 10);
	if (getline(&lineptr, &n, stdin) == -1)
	{
		free_res(&lineptr, &n);
		write(1, &newln, 1);
		exit(96);
	}
	if (_strcmp(lineptr, "exit") == 1)
	{
		free_res(&lineptr, &n);
		exit(96);
	}
	else if (_strcmp(lineptr, "env") == 1)
	{
		print_env(env);
		return (0);
	}
	else if (*((int *)lineptr) == 10)
	{
		free_res(&lineptr, &n);
		exit(0);
	}
	num_tokens = count_tokens(lineptr);
	tokenize(argv, lineptr);
	if (access(argv[0], F_OK | X_OK) == -1)
	{
		perror(prog_n);
		free_res2(argv, num_tokens, lineptr);
		return (95);
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
