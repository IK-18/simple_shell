#include "shell.h"

/**
 * sigBlocker - blocks the Ctrl-C signal
 * @signum: signal number
 *
 * Return: Nothing
 */
void sigBlocker(__attribute__((unused)) int signum)
{
	_puts("\n$ ");
	_putchar(FLUSH);
}