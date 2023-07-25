#include "shell.h"

/**
 * execcmd - forks a an exec thread to run cmd
 * @pseudo: pseudo struct
 *
 * Return: Nothing
 */
void execcmd(pseudo_t *pseudo)
{
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("Error: ");
		eputs("Canont fork\n");
		return;
	}
	if (child == 0)
	{
		if (execve(pseudo->path, pseudo->argv, _getenviron(pseudo)) == -1)
		{
			free_pseudo(pseudo, 1);
			if (errno == EACCES)
				exit(126);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&(pseudo->status));
		if (WIFEXITED(pseudo->status))
		{
			pseudo->status = WEXITSTATUS(pseudo->status);
			if (pseudo->status == 126)
				_perror(pseudo, "Permission denied\n");
		}
	}
}
