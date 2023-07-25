#include "shell.h"

/**
 * _getline - function to store an entire line from input
 * @pseudo: pseudo struct
 * @lineptr: pointer to input buffer
 * @size: size of pointer buffer
 *
 * Return: number of characters from input, -1 on error
 */
ssize_t _getline(pseudo_t *pseudo, char **lineptr, size_t *size)
{
	static char buffer[BUF_SIZE];
	static size_t nothing, bufsize;
	ssize_t new_pos, bytes_read;
	size_t pos;
	char *newptr, *ptr, *chptr;

	if (lineptr == NULL || size == 0)
		return (-1);
	ptr = *lineptr;
	if (ptr && size)
		new_pos = *size;
	if (nothing == bufsize)
		nothing = bufsize = 0;
	bytes_read = rbuf(pseudo, buffer, &bufsize);
	if ((bytes_read == 0 && bufsize == 0) || bytes_read == -1)
		return (-1);
	chptr = _strchr(buffer + nothing, '\n');
	pos = chptr ? 1 + (unsigned int)(chptr - buffer) : bufsize;
	newptr = _realloc(ptr, new_pos, new_pos ? new_pos + pos : pos + 1);
	if (newptr == NULL)
		return (ptr ? free(ptr), -1 : 1);
	if (new_pos)
		_strncat(newptr, buffer, pos);
	else
		_strncpy(newptr, buffer, pos + 1);
	new_pos += pos - nothing;
	nothing = pos;
	ptr = newptr;
	if (size)
		*size = new_pos;
	*lineptr = ptr;
	return (new_pos);
}
