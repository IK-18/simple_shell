#include "shell.h"

/**
 * inbuilt - function that checks if string is an in-built command
 * @args: string array
 * @env: environment variable
 *
 * Return: 1 if true, 0 if false
 */

int inbuilt(char **args, char **env)
{
	int i;

	if (_strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
			perror("Error: Missing directory argument for 'cd' command.");
		else
		{
			if (chdir(args[1]) != 0)
				perror("Error: Failed to change directory.");
		}
		return (1);
	}
	else if (_strcmp(args[0], "pwd") == 0)
	{
		char cwd[MAX_CMD_LEN];
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			write(STDOUT_FILENO, cwd, _strlen(cwd));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
			perror("Error: Failed to get current working directory.");
		return (1);
	}
	else if (_strcmp(args[0], "exit") == 0)
	{
		write(STDOUT_FILENO, "Exiting the shell...\n", 21);
		exit(0);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		for (i = 0; env[i] != NULL; i++)
		{
			write(STDOUT_FILENO, env[i], _strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		return (1);
	}
	return (0);
}
