#include "main.h"

/**
 * kill_cp - kills a called and a calling process
 * @child_pid: this is the called or child process
 * @main_pid: this is the calling or parent process
 */
void kill_cp(pid_t child_pid, pid_t main_pid)
{
	kill(main_pid, SIGINT);
	kill(child_pid, SIGINT);
}

/**
 * _strcmp - compares two strings
 * @string1: the first string to be compared
 * @string2: the second string to be compared
 * Return: 1 if equal, otherwise, it returns 0
 */
int _strcmp(char *string1, char *string2)
{
	int str1_len = 0, str2_len = 0, i, res = 0;

	for (i = 0; string1[i]; i++)
		str1_len++;

	for (i = 0; string2[i]; i++)
		str2_len++;

	if (str1_len == str2_len)
	{
		for (i = 0; i < str1_len; i++)
		{
			if ((int)string1[i] == (int)string2[i])
				res = 1;
			else
			{
				res = 0;
				break;
			}
		}
	}
	else
		return (0);
	return (res);
}
