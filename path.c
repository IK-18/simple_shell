#include "shell.h"

char *get_cmd_path(char *cmd, char **path_list)
{
	char *cmd_path = malloc(MAX_CMD_LEN);
	int i;

	i = 0;
	if (cmd_path == NULL)
	{
		perror("Error: Failed to allocate memory for command path.");
		return (NULL);
	}
	if (path_list == NULL)
	{
		perror("Error: Path list is NULL.");
		free(cmd_path);
		return (NULL);
	}
	while (path_list[i] != NULL)
	{
		_strcpy(cmd_path, path_list[i]);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, cmd);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		i++;
	}
	perror("Error: Command not found in path.");
	free(cmd_path);
	return (NULL);
}
