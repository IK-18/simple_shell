#include "shell.h"

/**
 * parse_cmd - parses the commands into an array
 * @str: string to be split
 *
 * Return: array
 */

char **parse_cmd(char *str)
{
	char **s, *token;
	int i = 0, j = 0;

	s = malloc(8 * sizeof(char *));
	if (s == NULL)
	{
		perror("Can't allocate space");
		return (NULL);
	}
	token = _strtok(str, " ");
	while (token != NULL)
	{
		if (i >= MAX_ARGS)
		{
			perror("Error: too many arguments");
			return (NULL);
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
			perror("Can't allocate space");
			return (NULL);
		}
		i++;
		s = realloc(s, sizeof(char *) * (i + 1));
		j = 0;
		token = _strtok(NULL, " ");
	}
	s[i] = NULL;
	return (s);
}
