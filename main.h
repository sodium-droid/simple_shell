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

#endif
