#include "shell.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: argument array
 * @env: environment variable
 *
 * Return: 0 on succes, 1 on failure
 */

int main(int argc, char **argv, char **env)
{
	char lineptr[MAX_CMD_LEN], *av[MAX_ARGS], **path_list;
	ssize_t n = MAX_CMD_LEN;
	size_t char_len;
	int nread;

	if (argc > MAX_ARGS)
		argv[MAX_ARGS] = NULL;
	while (1)
	{
		prompt();
		nread = read(STDIN_FILENO, lineptr, n);
		if (nread == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		char_len = _strlen(lineptr);
		if (lineptr[char_len - 1] == '\n')
			lineptr[char_len - 1] = '\0';
		*av = parse_cmd(lineptr);
		if (av == NULL)
			continue;
		path_list = ptchk(env);
		execmd(av, env, path_list);
	}
	free(lineptr);
	free(path_list);
	return (0);
}
