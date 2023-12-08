#include "main.h"

/**
 * main - entry to the program
 * @ac: argument's counter
 * @av: argument's vector
 * Return: 0, if no error, otherwise 1.
 */
int main(int ac, char **av)
{
	char *prog_n = av[ac - 1];
	int status;
	size_t n = 0;
	char *lineptr = NULL;
	char *msg = "#cisfun$ ";
	int does_exist;
	char *argv[2];
	struct stat st;
	pid_t ps;
	char newline = '\n';

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
			write(0, msg, 10);
			if (getline(&lineptr, &n, stdin) == EOF)
			{
				free_res(&lineptr, &n);
				exit(96);
			}
			if (*((int *)lineptr) == 10)
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
			if ((execve(argv[0], argv, environ) == -1))
			{
				perror(prog_n);
				free_res(&lineptr, &n);
				return (0);
			}
		}
		else
		{
			waitpid(ps, &status, 0);
			if (WIFEXITED(status) && (WEXITSTATUS(status) > 0))
			{
				free(lineptr);
				lineptr = NULL;
				n = 0;
				write(0, &newline, 1);
				break;
			}
		}
	}
	return (0);
}
