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
	char cwd[MAX_CMD_LEN];

	if (_strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			perror("Error: Missing directory argument for 'cd' command.");
		}
		else if (chdir(args[1]) != 0)
			perror("Error: Failed to change directory.");
		return 1;
	}
	else if (_strcmp(args[0], "pwd") == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("Error: Failed to get current working directory.");
		}
		else
		{
			_puts(cwd);
			_putchar('\n');
		}
		return 1;
	}
	else if (_strcmp(args[0], "exit") == 0)
	{
		_puts("Exiting the shell...\n");
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		for (int i = 0; env[i] != NULL; i++)
		{
			_puts(env[i]);
			_putchar('\n');
		}
		return 1;
	}
	return 0;
}
