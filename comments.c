#include "shell.h"

/**
 * comments - handles comments
 * @buffer: address of the buffer
 *
 * Return: Nothing
 */
void comments(char *buffer)
{
	int i = 0;

	while (buffer[i] != '\0')
	{
		if (buffer[i] == '#' && (!i || buffer[i - 1] == ' '))
		{
			buffer[i] = '\0';
			break;
		}
		i++;
	}
}