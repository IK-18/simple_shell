#include "shell.h"

/**
 * main - main function
 * @argc: arguent counter
 * @argv: argument array
 * @env: environment variable
 *
 * Return: 0 on succes, 1 on failure
 */

int main(int argc, char *argv[], char *env[])
{
	char *lineptr, *nc;
	size_t n = 20, inbt = 0, path = 4;
	ssize_t char_len;
	char **av;

	if (argc > 1)
		argv[1] = NULL;
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
			if (_strcmp("exit", av[0]) == 0)
				break;
			/*inbt = inbuilt(av[0]);*/
			nc = fchk(av[0]);
			if (nc != NULL)
				forkexe(av, env);
		}
	}
	inbt++;
	path++;
	nc = "hello";
	free(nc);
	free(lineptr);
	free(av);
	exit(EXIT_SUCCESS);
}
