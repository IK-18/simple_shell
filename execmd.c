#include "shell.h"

/**
 * execmd - creates a child process to allow the parent process (prompt)
 * still run via execve even though processing user input
 * @av: string array
 * @env: environment variable
 * @path_list: list of path variables
 *
 * Return: nothing
 */

void execmd(char **av, char **env, char **path_list)
{
	char path[MAX_CMD_LEN];
	int i;

	if (inbuilt(av, env))
		return;
	if (access(av[0], X_OK) == 0)
	{
		execve(av[0], av, env);
		perror("Error: Unable to execute command.");
		return (1);
	}
	for (i = 0; path_list[i] != NULL; i++)
	{
		_strcpy(path, path_list[i]);
		_strcat(path, "/");
		_strcat(path, av[0]);
		if (access(path, X_OK) == 0)
		{
			execve(path, av, env);
			perror("Error: Unable to exexcute command.");
			return (1);
		}
	}
	perror("Error: Command not found.");
}
