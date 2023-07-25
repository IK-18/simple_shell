#include "shell.h"

/**
 * _ismulticmd - test if current char is a multicmd delimeter
 * @pseudo: pseudo struct
 * @buffer: buffer
 * @curr: current address of position in buffer
 *
 * Return: 1 if multi cmd, 0 otherwise
 */
int _ismulticmd(pseudo_t *pseudo, char *buffer, size_t *curr)
{
	size_t pos = *curr;

	switch (buffer[pos])
	{
	case '|':
		if (buffer[pos + 1] == '|')
		{
			buffer[pos] = '\0';
			pos++;
			pseudo->cmd_buffer_type = OR;
			break;
		}
		else
			return (FAILURE);
	case '&':
		if (buffer[pos + 1] == '&')
		{
			buffer[pos] = '\0';
			pos++;
			pseudo->cmd_buffer_type = AND;
			break;
		}
		else
			return (FAILURE);
	case ';':
		buffer[pos] = '\0';
		pseudo->cmd_buffer_type = MULTI_CMD;
		break;
	default:
		return (FAILURE);
	}
	*curr = pos;
	return (SUCCESS);
}
