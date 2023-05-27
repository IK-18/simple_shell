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
	char lineptr[MAX_CMD_LEN], **av, **path_list;
	size_t char_len;
	int nread;

	if (argc > MAX_ARGS)
		argv[MAX_ARGS] = NULL;
	while (1)
	{
		prompt();
		nread = read(STDIN_FILENO, lineptr, MAX_CMD_LEN);
		if (nread == -1)
			exit(EXIT_FAILURE);
		else if (nread == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		char_len = _strlen(lineptr);
		if (lineptr[char_len - 1] == '\n')
			lineptr[char_len - 1] = '\0';
		av = parse_cmd(lineptr);
		if (av == NULL || _strcmp(av[0], "\n") == 0)
			continue;
		if (inbuilt(av, env) == 1)
		{
			free(av);
			continue;
		}
		execmd(av[0], av, env, path_list);
		free(av);
	}
	return (0);
}
