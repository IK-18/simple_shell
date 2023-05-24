#include "shell.h"

/**
 * _puts - prints a string
 * @str: string
 * Return: Always 0
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}
