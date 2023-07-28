#include "shell.h"

/**
 * _cd - changes the current directory of the process
 * @pseudo: pseudo struct
 *
 *  Return: 0 on success, 1 otherwise
 */
int _cd(pseudo_t *pseudo)
{
	char *cwd, *dir, buffer[1024];
	int ret;

	cwd = getcwd(buffer, 1024);
	if (cwd == NULL)
		_puts("Failed to get current working directory\n");
	if (pseudo->argv[1] == NULL)
	{
		dir = _getenv(pseudo, "HOME=");
		if (dir == NULL)
			ret =
				chdir((dir = _getenv(pseudo, "PWD=")) ? dir : "/");
		else
			ret = chdir(dir);
	}
	else if (!_strcmp(pseudo->argv[1], "-"))
	{
		if (_getenv(pseudo, "OLDPWD=") == NULL)
		{
			_puts(cwd);
			_putchar('\n');
			return (EXIT_FAILURE);
		}
		_puts(_getenv(pseudo, "OLDPWD=")), _putchar('\n');
		ret =
			chdir((dir = _getenv(pseudo, "OLDPWD=")) ? dir : "/");
	}
	else
		ret = chdir(pseudo->argv[1]);
	if (ret < 0)
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
