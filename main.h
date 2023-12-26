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
#include <errno.h>
#include <signal.h>
int shell_init(char *prog_n, char **lineptr_to_update, char **env);
void free_res(char **lineptr, size_t *n);
void update_close(int c_val);
void get_lineptr(char **lineptr, char **lineptr_add);
void kill_cp(pid_t child_pid, pid_t main_pid);
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
int _strcmp(char *string1, char *string2);
void free_res2(char *argv[], int num_tokens, char *lineptr);
char *_strcpy(char *dest, char *src);
int count_tokens(char *lineptr);
void tokenize(char *argv[], char *lineptr);
int _strlen(char *string);
void print_env(char **env);
int to_int(char *str);
void exit_with_status(char *lineptr);
int is_exit(char *lineptr, char *exit_keyword);

#endif
