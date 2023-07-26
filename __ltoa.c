#include "shell.h"

/**
 * __ltoa - converts a list to an array of strings
 * @list: pointer to first node of list
 *
 * Return: array of strings or NULL
 */
char **__ltoa(list_t *list)
{
	list_t *node = list;
	size_t i = list_len(list), j;
	char **arr;
	char *str;

	if (!list || !i)
		return (NULL);
	arr = malloc(sizeof(char *) * (i + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (node)
	{
		str = malloc(_strlen(node->str) + 1);
		if (str == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(arr[j]);
				j++;
			}
			free(arr);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		arr[i] = str;
		node = node->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}