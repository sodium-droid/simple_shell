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
	int status, status_p;
	char *lineptr = NULL;
	pid_t ps, child_pid, main_pid;

	main_pid = getpid();
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
			child_pid = getpid();
			status_p = shell_init(prog_n, &lineptr, env);
			if (status_p == 96)
			{
				free(lineptr);
				kill_cp(child_pid, main_pid);
			}
			else
				kill(child_pid, SIGINT);
		}
		else
		{
			waitpid(ps, &status, 0);
			free(lineptr);
			if (!(isatty(STDIN_FILENO)))
				break;
		}
	}
	return (0);
}
