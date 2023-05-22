#include "shell.h"

/**
 * forkexe - creates a child process to allow the parent process (prompt)
 * still run via execve even though processing user input
 * */

void forkexe(char *str, char **av, char **env)
{
	pid_t child;
	int status;

	child = fork(); /*system call that creates a child process from parent*/
	/*checks return value of fork*/
	if (child == -1)
	{
		free(str);
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		/*runs command and checks value simultaneously*/
		if (execve(av[0], av, env) == -1)
			printf("IKShell$: No such file or directory\n");
	}
	/*monitor the status of the child process and wait*/
	else
		wait(&status);
}