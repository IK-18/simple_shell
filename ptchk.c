#include "shell.h"

/**
 * ptchk - checks if the string has the path "/bin"
 * @envp: environment variable
 *
 * Return: 0 if false, 1 if true
 */

char **ptchk(char **envp)
{
	char **path_list, *path_env_var;
	int paths_len = 0, i;

	path_list = malloc(MAX_ARGS * sizeof(char *));
	for (i = 0; envp[i] != NULL; i++)
	{
		if (_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_env_var = envp[i] + 5;
			path_list[paths_len] = _strtok(path_env_var, ":");
			while (path_list[paths_len] != NULL)
			{
				paths_len++;
				if (paths_len >= MAX_ARGS)
				{
					perror("Error: Too many diretories in PATH");
					free(path_list);
					exit(EXIT_FAILURE);
				}
				path_list[paths_len] = _strtok(NULL, ":");
			}
			break;
		}
	}
	return (path_list);
}
