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
extern char **environ;
int shell_init(char *prog_n);
void free_res(char **lineptr, size_t *n);
void free_res2(char *argv[], int num_tokens, char *lineptr);
char *_strcpy(char *dest, char *src);
int count_tokens(char *lineptr);
void tokenize(char *argv[], char *lineptr);

#endif
