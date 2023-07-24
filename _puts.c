#include "shell.h"

/**
 * _puts - prints a string
 * @str: string
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i;

	if (!str)
		return;
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}
