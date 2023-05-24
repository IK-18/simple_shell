#include "shell.h"

/**
 * ptchk - checks if the string has the path "/bin"
 * @str: string to be checked
 *
 * Return: 0 if false, 1 if true
 */

int ptchk(char *str)
{
	char *bin = "/bin/", *ptr, *x;
	int i = 0, j = 0;

	ptr = malloc(sizeof(char) * 50);
	if (ptr == NULL)
		return (0);
	/*comparing each character to check bin*/
	while (bin[i] != '\0')
	{
		if (bin[i] != str[i])
		{
			free(ptr);
			return (0);
		}
		i++;
	}
	/*concatenates*/
	while (str[i] != '\0')
	{
		ptr[j] = str[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	x = fchk(ptr);
	if (j != NULL)
	{
		free(ptr);
		return (1);
	}
	return (0);
}