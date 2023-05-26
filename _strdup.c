#include "shell.h"

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 *
 * Return: new string
 */

char *_strdup(const char *str)
{
	char *newstr = NULL;
	int len, i;

	len = 0;
	while (*(str + len) != '\0')
		len++;
	newstr = malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		*(newstr + i) = *(str + i);
	*(newstr + i) = '\0';
	return (newstr);
}
