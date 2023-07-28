#include "shell.h"

/**
 * chkmulticmd - checks if still in MULTI_CMD based on previous state
 * @pseudo: pseudo struct
 * @b: char buffer
 * @cur: current address of position in buffer
 * @st: starting position in buffer
 * @len: length of buffer
 *
 * Return: Nothing
 */
void chkmulticmd(pseudo_t *pseudo, char *b, size_t *cur, size_t st, size_t len)
{
	size_t i = *cur;

	if (pseudo->cmd_buffer_type == AND)
	{
		if (pseudo->status)
		{
			b[st] = 0;
			i = len;
		}
	}
	if (pseudo->cmd_buffer_type == OR)
	{
		if (pseudo->status == 0)
		{
			b[st] = 0;
			i = len;
		}
	}
	*cur = i;
}