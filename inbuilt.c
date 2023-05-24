#include "shell.h"

/**
 * inbuilt - function that checks if string is an in-built command
 * @str: string to be checked
 *
 * Return: 1 if true, 0 if false
 */

int inbuilt(char *str)
{
	char **tmp;
	int i = 0;
	char cwd[1024];

	tmp = malloc(sizeof(char *) * 3);
	if (tmp == NULL)
		return (0);
	tmp[0] = "cd";
	tmp[1] = "exit";
	tmp[2] = "pwd";
	while (i < 3)
	{
		if (_strcmp(tmp[i], str))
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		chdir(str);
		free(tmp);
		return (1);
	case 1:
		_puts("bye");
		free(tmp);
		return (2);
	case 2:
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			free(cwd);
			return (0);
		}
		_puts("Current working directory: ");
		_puts(cwd);
		free(tmp);
		return (1);
	default:
		free(tmp);
		return (0);
	}
	return (0);
}
