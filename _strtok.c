#include "shell.h"

/**
 * _strtok - splits a string into tokens separated by a delimiter
 * ignoring repeated delimiters
 * @str: string to be split
 * @delim: delimiter
 *
 * Return: pointer to array of strings or NULL
 */
char **_strtok(char *str, char *delim)
{
	char **arr;
	int a, b, c, d, len = 0;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!delim)
		delim = " ";
	for (a = 0; str[a] != '\0'; a++)
	{
		if (!_chrcmp(str[a], delim) && (_chrcmp(str[a + 1], delim) || !str[a + 1]))
			len++;
	}
	if (len == 0)
		return (NULL);
	arr = malloc((len + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	for (a = 0, b = 0; b < len; b++)
	{
		for (; _chrcmp(str[a], delim); a++)
			;
		for (c = 0; !_chrcmp(str[a + c], delim) && str[a + c]; c++)
			;
		arr[b] = malloc((c + 1) * sizeof(char));
		if (!arr[b])
		{
			for (c = 0; c < b; c++)
				free(arr[c]);
			free(arr);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			arr[b][d] = str[a++];
		arr[b][d] = 0;
	}
	arr[b] = NULL;
	return (arr);
}
