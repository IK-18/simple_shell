#include "shell.h"

/**
 * _perror - prints an error message
 * @pseudo: pseudoinfo struct
 * @estr: error string
 *
 * Return: Nothing
 */
void _perror(pseudo_t *pseudo, char *estr)
{
	eputs(pseudo->fname);
	eputs(": ");
	dprint(pseudo->linecount, STDERR_FILENO);
	eputs(": ");
	eputs(pseudo->argv[0]);
	eputs(": ");
	eputs(estr);
}