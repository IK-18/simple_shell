#include "shell.h"

/**
 * ltoa - converts a lst to an array of strings
 * @list: pointer to first node of list
 *
 * Return: array of strings or NULL
 */
char **ltoa(list_t *list)
{
	list_t *node = list;
	size_t i = list_len(list), j;
	char **arr;
	char *str;

	if (list == NULL || !i)
		return (NULL);
	arr = malloc(sizeof(char *) * (i + 1));
	if (arr == NULL)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (str == NULL)
		{
			for (j = 0; j < i; j++)
				free(arr[j]);
			free(arr);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		arr[i] = str;
	}
	arr[i] = NULL;
	return (arr);
}