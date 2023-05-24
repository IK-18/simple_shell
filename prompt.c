#include "shell.h"

/**
 * prompt - displays a prompt and waits and responds to user input
 * @argv: array containing user input
 * @env: environment variable
 *
 * Return: Nothing
 */

void prompt(char **env)
{
	char *lineptr, *nc;
	size_t n = 20, path = 4;
	ssize_t char_len;
	char **av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("IKShell$ ");
		lineptr = malloc(sizeof(char) * n);
		char_len = _getline(&lineptr, &n);
		/*frees the pointer after reading characters if invalid*/
		if (char_len == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		if (*lineptr != '\n')
		{
			/*stores the user input as av*/
			av = chrstrtok(lineptr);
			if (_strcmp("exit", av[0]))
				break;
			nc = fchk(av[0]);
			if (nc != NULL)
				av[0] = nc;
			path = ptchk(av[0]);
			if (path)
				forkexe(av, env);
			if (nc == NULL && !path)
				_puts("./shell: No such file or directory\n");
		}
	}
	free(nc);
	free(lineptr);
	free(av);
	exit(EXIT_SUCCESS);
}