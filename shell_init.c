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
	int does_exist;
	char **args;
	const char *default_path = getenv("PATH");

	printf("#cisfun$ ");
	if (getline(&lineptr, &n, stdin) == -1)
	{
		perror("Error reading command");
		return (1);
	}
	cmd = strtok(lineptr, "\n");
	does_exist = check_command(cmd, default_path);
	if (does_exist == 0)
	{
		args = parse_arguments(cmd);
		if (args != NULL)
			execute_command(args, default_path);
		else
			printf("Error parsing arguments\n");
		free(args);
	}
	else if (strcmp(cmd, "exit") == 0)
	{
		free(lineptr);
		exit(0);
	}
	else
	{
		printf("%s: No such file or directory\n", prog_n);
		return (1);
	}
	free(lineptr);
	return (0);
}
