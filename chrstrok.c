#include "shell.h"

/**
 * chrstrtok - splits a string into tikens separated by " "
 * @str: string to be split
 *
 * Return: token
 */

char **chrstrtok(char *str)
{
	static char **s, *token;
	int i = 0, j = 0;

	s = malloc(8 * sizeof(char *));
	if (s == NULL)
	{
		perror("Can't allocate space");
		exit(EXIT_FAILURE);
	}
	/*splits input into words separated by " "*/
	token = _strtok(str, " ");
	while (token != NULL)
	{
		/*checks for newline character*/
		while (token[j])
		{
			if (token[j] == '\n')
				token[j] = '\0';
			j++;
		}
		s[i] = token;
		i++;
		j = 0;
		token = _strtok(NULL, " ");
	}
	/*NULL-terminates*/
	s[i] = NULL;
	return (s);
}