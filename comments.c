#include "shell.h"

/**
 * comments - handles comments
 * @buffer: address of the buffer
 *
 * Return: Nothing
 */
void comments(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
		if (buffer[i] == '#' && (!i || buffer[i - 1] == ' '))
		{
			buffer[i] = '\0';
			break;
		}
}