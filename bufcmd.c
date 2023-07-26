#include "shell.h"

/**
 * bufcmd - buffers mulitple commands
 * @pseudo: pseudo struct
 * @buffer: buffer
 * @len: length of input
 *
 * Return: bytes read
 */
ssize_t bufcmd(pseudo_t *pseudo, char **buffer, size_t *len)
{
	ssize_t bytes_read = 0;
	size_t len_ptr = 0;

	if (!*len)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigBlocker);
#if GETLINE
		bytes_read = getline(buffer, &len_ptr, stdin);
#else
		bytes_read = _getline(pseudo, buffer, &len_ptr);
#endif
		if (bytes_read > 0)
		{
			if ((*buffer)[bytes_read - 1] == '\n')
			{
				(*buffer)[bytes_read - 1] = '\0';
				bytes_read--;
			}
			pseudo->linecount_flag = 1;
			comments(*buffer);
			add_history(pseudo, *buffer, pseudo->histcount++);
			/* if (_strchr(*buffer, ';')) */
			{
				*len = bytes_read;
				pseudo->cmd_buffer = buffer;
			}
		}
	}
	return (bytes_read);
}