#include "shell.h"

/**
 * _getline - function to store an entire line from input
 * @lineptr: pointer to input buffer
 * @n: size of input buffer
 *
 * Return: number of characters
 */

int _getline(char **lineptr, size_t *n)
{
	static char buffer[1024];
	static char *buf_pos = buffer;
	static size_t buf_remaining;
	int num_chars, total_read = 0;
	char *newline, *line;

	line = *lineptr;
	if (line == NULL || *n == 0)
	{
		*lineptr = malloc(1024);
		if (*lineptr == NULL)
			return (-1);
		*n = 1024;
		line = *lineptr;
	}
	while (buf_remaining || (buf_remaining = read(STDIN_FILENO, buffer, 1024)))
	{
		newline = memchr(buf_pos, '\n', buf_remaining);
		if (newline)
		{
			num_chars = newline - buf_pos + 1;
			memcpy(line, buf_pos, num_chars);
			line[num_chars - 1] = '\0';
			buf_pos = newline + 1;
			buf_remaining -= num_chars;
			total_read += num_chars;
			return (total_read);
		}
		num_chars = buf_remaining;
		memcpy(line, buf_pos, num_chars);
		line += num_chars;
		buf_remaining = 0;
		buf_pos = buffer;
	}
	return (total_read ? total_read : -1);
}
