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
	int paths_len, i;

	paths_len = 0;
	path_list = realloc(path_list, MAX_ARGS * sizeof(char *));
	if (path_list == NULL)
	{
		perror("Error: Failed to allocate memory for path list.");
		exit(EXIT_FAILURE);
	}
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
					perror("Error: Too many directories in PATH.");
					free(path_list);
					exit(EXIT_FAILURE);
				}
				path_list[paths_len] = _strtok(NULL, ":");
			}
			break;
		}
	}
	if (paths_len == 0)
	{
		perror("Error: PATH environment variable not found.");
		free(path_list);
		exit(EXIT_FAILURE);
	}
	path_list[paths_len] = NULL;
	return (path_list);
}
