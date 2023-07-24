#include "shell.h"

/**
 * rbuf - reads a buffer
 * @pseudo: pseudo struct
 * @buffer: buffer
 * @size: size
 *
 * Return: bytes read from buffer
 */
ssize_t rbuf(pseudo_t *pseudo, char *buffer, size_t *size)
{
	ssize_t bytes_read = 0;

	if (*size)
		return (EXIT_SUCCESS);
	bytes_read = read(pseudo->readfd, buffer, BUF_SIZE);
	if (bytes_read >= 0)
		*size = bytes_read;
	return (bytes_read);
}