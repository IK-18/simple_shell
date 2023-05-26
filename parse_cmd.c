#include "shell.h"

/**
 * parse_cmd - parses the commands into an array
 * @str: string to be split
 *
 * Return: array
 */

char **parse_cmd(char *str)
{
	char **s, *token, *buf;
	int i, j, buf_size = MAX_BUF_SIZE;

	i = 0;
	j = 0;
	s = malloc((MAX_ARGS + 1) * sizeof(char *));
	if (s == NULL)
	{
		perror("Error: Failed to allocate memory for command arguments.");
		return NULL;
	}
	buf = malloc(buf_size * sizeof(char));
	if (buf == NULL)
	{
		perror("Error: Failed to allocate memory for command buffer.");
		free(s);
		return NULL;
	}
	token = _strtok(buf, " ");
	while (token != NULL)
	{
		if (i >= MAX_ARGS)
		{
			perror("Error: Too many arguments.");
			free(s);
			free(buf);
			return NULL;
		}
		if (j >= buf_size)
		{
			char *new_buf = realloc(buf, buf_size * 2);
			if (new_buf == NULL)
			{
				perror("Error: Failed to allocate memory for command buffer.");
				free(s);
				free(buf);
				return NULL;
			}
			buf = new_buf;
			buf_size *= 2;
		}
		if (token[j] == '\"' || token[j] == '\'')
		{
			char quote = token[j];
			j++;
			while (token[j])
			{
				if (token[j] == quote)
				{
					token[j] = '\0';
					break;
				}
				j++;
			}
		}
		else if (token[j] == '\\')
		{
			j++;
			if (token[j] == '\"' || token[j] == '\'' || token[j] == '\\')
			{
				memmove(&token[j - 1], &token[j], _strlen(token + j) + 1);
			}
		}
		while (token[j])
		{
			if (token[j] == '\n')
				token[j] = '\0';
			j++;
		}
		s[i] = _strdup(token);
		if (s[i] == NULL)
		{
			perror("Error: Failed to allocate memory for command argument.");
			free(s);
			free(buf);
			return NULL;
		}
		i++;
		j = 0;
		token = _strtok(NULL, " ");
	}
	s[i] = NULL;
	free(buf);
	return s;
}