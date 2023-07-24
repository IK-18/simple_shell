#include "shell.h"

/**
 * chkmulticmd - checks if still in MULTI_CMD based on previous state
 * @pseudo: pseudo struct
 * @buffer: char buffer
 * @curr: current address of position in buffer
 * @start: starting position in buffer
 * @len: length of buffer
 *
 * Return: Nothing
 */
void chkmulticmd(pseudo_t *pseudo, char *buffer, size_t *curr, size_t start, size_t len)
{
	size_t i = *curr;

	if (pseudo->cmd_buffer_type == AND && pseudo->status)
	{
		buffer[start] = '\0';
		i = len;
	}
	if (pseudo->cmd_buffer_type == OR && !pseudo->status)
	{
		buffer[start] = '\0';
		i = len;
	}
	*curr = i;
}