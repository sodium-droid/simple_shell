#include "main.h"

/**
 * main - entry to the simple shell program
 * @ac: argument's counter
 * @av: argument's vector
 * Return: 0, if no error, otherwise 1.
 */
int main(int ac, char **av)
{
	int status;
	pid_t ps;

	while (1)
	{
		ps = fork();
		if (ps == -1)
		{
			perror("Error: Can't create a new process\n");
			exit(98);
		}
		if (ps == 0)
			shell_init(av[ac - 1]);
		else
			wait(&status);
		}
	return (0);
}
