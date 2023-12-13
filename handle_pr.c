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
