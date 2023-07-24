#include "shell.h"

/**
 * _cd - changes the current directory of the process
 * @pseudo: pseudo struct
 *
 *  Return: 0 on success, 1 otherwise
 */
int _cd(pseudo_t *pseudo)
{
	char *cwd, buffer[1024];
	int ret;

	cwd = getcwd(buffer, 1024);
	if (cwd == NULL)
	{
		_puts("Failed to get current working directory\n");
		return (EXIT_FAILURE);
	}
	if (pseudo->argv[1] == NULL)
	{
		if (_getenv(pseudo, "HOME=") == NULL)
			ret = chdir((_getenv(pseudo, "PWD=")) ? _getenv(pseudo, "PWD=") : "/");
		else
			ret = chdir(_getenv(pseudo, "HOME="));
	}
	else if (_strcmp(pseudo->argv[1], "-") == 0)
	{
		if (_getenv(pseudo, "OLDPWD=") == NULL)
		{
			_puts(cwd);
			_putchar('\n');
			return (EXIT_FAILURE);
		}
		_puts(_getenv(pseudo, "OLDPWD=")), _putchar('\n');
		ret = chdir((_getenv(pseudo, "OLDPWD=")) ? _getenv(pseudo, "OLDPWD=") : "/");
	}
	else
		ret = chdir(pseudo->argv[1]);
	if (ret == -1)
	{
		_perror(pseudo, "can't cd to ");
		eputs(pseudo->argv[1]), eputchar('\n');
	}
	else
	{
		_setenv(pseudo, "OLDPWD", _getenv(pseudo, "PWD="));
		_setenv(pseudo, "PWD", getcwd(buffer, 1024));
	}
	return (EXIT_SUCCESS);
}