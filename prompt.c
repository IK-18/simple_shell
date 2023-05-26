#include "shell.h"

/**
 * prompt - displays a prompt at the beginning and after every command
 *
 * Return: nothing
 */

void prompt()
{
	if (isatty(STDIN_FILENO))
	{
		_puts("IKShell$ ");
		fflush(stdout);
	}
}
