#include "shell.h"

/**
 * eputs - prints an error string
 * @str: string

 * Return: Nothing
 */
void eputs(char *str)
{
	int i;

	if (!str)
		return;
	for (i = 0; str[i] != '\0'; i++)
		eputchar(str[i]);
}
