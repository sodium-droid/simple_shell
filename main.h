#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

extern char **environ;
int shell_init(char *prog_n);
int check_command(const char *cmd, const char *path);
char **parse_arguments(const char *cmd);
void execute_command(char **args, const char *default_path);
const char *get_command_path(const char *cmd, const char **command_paths);

/*string.c*/
int _putchar(char c);
int _strlen(char *s);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
int _strcspn(const char *str, const char *check);

/*strings.c*/
char *_strncat(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
int _strcmp(char *str1, char *str2);

#endif
