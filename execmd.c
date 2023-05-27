#include "shell.h"

/**
 * execmd - creates a child process to allow the parent process (prompt)
 * still run via execve even though processing user input
 * @cmd: first command
 * @av: string array
 * @env: environment variable
 * @path_list: list of path variables
 *
 * Return: nothing
 */

void execmd(char *cmd, char **av, char **env, char **path_list)
{
	pid_t pid;
	int status;
	char *cmd_path = NULL;

	if (inbuilt(av, env) == 0)
	{
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
		{
			cmd_path = get_cmd_path(cmd, path_list);
			if (cmd_path == NULL)
				exit(EXIT_FAILURE);
			if (access(cmd_path, X_OK) == -1)
			{
				free(cmd_path);
				exit(EXIT_FAILURE);
			}
			if (execve(cmd_path, av, env) == -1)
			{
				free(cmd_path);
				exit(EXIT_FAILURE);
			}
			free(cmd_path);
		}
		else
		{
			if (waitpid(pid, &status, 0) == -1)
				exit(EXIT_FAILURE);
			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
				perror("Error: Command exited with status");
		}
	}
}
