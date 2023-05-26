#include "shell.h"

/**
 * main - main function
 * @env: environment variable
 *
 * Return: 0 on succes, 1 on failure
 */

int main(char **env)
{
	char lineptr[MAX_CMD_LEN], *av[MAX_ARGS], **path_list;
	size_t n = MAX_CMD_LEN;
	ssize_t char_len;

	while (1)
	{
		prompt();
		lineptr = malloc(sizeof(char) * n);
		char_len = _getline(&lineptr, &n, stdin);
		if (char_len == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		if (lineptr[char_len - 1] == '\n')
			lineptr[char_len - 1] = '\0';
		av = parse_cmd(lineptr);
		if (av == NULL)
			continue;
		path_list = ptchk(env);
		execmd(av, env, path_list);
	}
	free(lineptr);
	free(path_list);
	return (0);
}
