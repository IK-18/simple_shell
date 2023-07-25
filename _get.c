#include "shell.h"

/**
 * _get - gets a line excluding the newline
 * @pseudo: pseudo struct
 *
 * Return: bytes read by getline
 */
ssize_t _get(pseudo_t *pseudo)
{
	static char *buffer;
	static size_t pos, new_pos, len;
	ssize_t bytes_read = 0;
	char **buf_ptr = &(pseudo->args), *ptr;

	_putchar(FLUSH);
	bytes_read = bufcmd(pseudo, &buffer, &len);
	if (bytes_read < 0)
		return (-1);
	if (len)
	{
		new_pos = pos;
		ptr = buffer + pos;
		chkmulticmd(pseudo, buffer, &new_pos, pos, len);
		for (new_pos; new_pos < len; new_pos++)
		{
			if (_ismulticmd(pseudo, buffer, &new_pos))
				break;
		}
		pos = new_pos + 1;
		if (pos >= len)
		{
			pos = len = 0;
			pseudo->cmd_buffer_type = NORM;
		}
		*buf_ptr = ptr;
		return (_strlen(ptr));
	}
	*buf_ptr = buffer;
	return (bytes_read);
}
