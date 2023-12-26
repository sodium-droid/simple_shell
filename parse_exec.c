#include "main.h"

/**
 *check_command - checks if cmd is in path
 *@cmd: command passed to shell
 *@path: PATH to required environment variable
 *Return: 0 or 1.
 */

int check_command(const char *cmd, const char *path)
{
	char *token;
	char *path_copy = strdup(path);
	char cmd_path[MAX_COMMAND_LENGTH];
	
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		snprintf(cmd_path, sizeof(cmd_path), "%s/%s", token, cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			free(path_copy);
			return (0);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (1);
}
/**
 *parse_arguments - function to parse argument given to shell
 *@cmd: commands
 *Return: arguments.
 */

char **parse_arguments(const char *cmd)
{
	char *token, *cmd_copy = strdup(cmd);
	int i, arg_count = 0;
	char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
	
	if (cmd_copy == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	if (args == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}
	token = strtok(cmd_copy, " ");
	while (token != NULL && arg_count < MAX_ARGUMENTS)
	{
		args[arg_count] = strdup(token);
		if (args[arg_count] == NULL)
		{
			perror("Memory allocation error");
			for (i = 0; i < arg_count; i++)
			{
				free(args[i]);
			}
			free(args);
			return (NULL);
		}
		token = strtok(NULL, " ");
		arg_count++;
	}
	free(cmd_copy);
	args[arg_count] = NULL;
	return (args);
}
/**
 *execute_command - exexcutes identified commands
 *@args: arguments to shell.
 */

void execute_command(char **args, const char *default_path)
{
	int status;
	pid_t pid = fork();
	
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		perror("exec");
		exit(1);
	}
	else
		waitpid(pid, &status, 0);
}
/**
 *get_command_path - Identify the path to the command
 *@cmd: command given to shell
 *@command_paths: path to environment variables.
 *
 */

const char *get_command_path(const char *cmd, const char **command_paths)
{
    int i;

    for (i = 0; command_paths[i] != NULL; i += 2)
    {
        if (strcmp(cmd, command_paths[i]) == 0)
            return (command_paths[i + 1]);
    }
    return (NULL);
}
