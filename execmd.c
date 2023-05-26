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

void execmd(char *cmd, char **argv, char **envp, char **path_list)
{
	pid_t pid;
	int status;
	char *cmd_path = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: Failed to fork child process.");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		// Child process

		// Get the full path to the command using the PATH directories
		cmd_path = get_cmd_path(cmd, path_list);
		if (cmd_path == NULL)
		{
			perror("Error: Command not found:");
			exit(EXIT_FAILURE);
		}

		// Execute the command
		if (access(cmd_path, X_OK) == -1)
		{
			perror("Error: Command not executable");
			free(cmd_path);
			exit(EXIT_FAILURE);
		}
		if (execve(cmd_path, argv, envp) == -1)
		{
			perror("Error: Failed to execute command.");
			free(cmd_path);
			exit(EXIT_FAILURE);
		}

		free(cmd_path);
	}
	else
	{
		// Parent process
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			perror("Error: Command exited with status");
		}
	}
}