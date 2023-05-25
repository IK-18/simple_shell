#include "shell.h"

/**
 * prompt - displays a prompt and waits and responds to user input
 * @env: environment variable
 *
 * Return: Nothing
 */

void prompt(char **env)
{
	char *lineptr, *nc;
	size_t n = 20, inbt = 0, path = 4;
	ssize_t char_len;
	char **av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("IKShell$ ");
		lineptr = malloc(sizeof(char) * n);
		char_len = _getline(&lineptr, &n);
		if (char_len == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		if (*lineptr != '\n')
		{
			av = chrstrtok(lineptr);
			if (_strcmp("exit", av[0]) == 1)
				break;
			inbt = inbuilt(av[0]);
			nc = fchk(av[0]);
			if (inbt == 0 && nc != NULL)
				av[0] = nc;
			path = ptchk(av[0]);
			if (path == 1)
				forkexe(av, env);
			if (nc == NULL && path == 0 && inbt == 0)
				_puts("its here./shell: No such file or directory\n");
		}
	}
	free(nc);
	free(lineptr);
	free(av);
	exit(EXIT_SUCCESS);
}
