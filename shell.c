#include "main.h"
/**
 * main - entry to the program
 * @ac: argument's counter
 * @av: argument's vector
 * @env: environment variable
 * Return: 0, if no error, otherwise 1.
 */
int main(int ac, char **av, char **env)
{
	char *prog_n = av[ac - 1];
	int status;
	char *lineptr = NULL;
	pid_t ps;

	while (1)
	{
		ps = fork();
		if (ps == -1)
		{
			perror("Error: Can't create a new process\n");
			exit(90);
		}
		else if (ps == 0)
		{
			if (shell_init(prog_n, &lineptr, env) == 95)
				exit(0);
			free(lineptr);
		}
		else
		{
			waitpid(ps, &status, 0);
			if (!(isatty(STDIN_FILENO)))
				break;
			else if (WEXITSTATUS(status) > 0)
				break;
		}
	}
	return (0);
}
