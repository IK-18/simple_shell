#include "shell.h"

/**
 * execinbuilt - executes an inbuilt command
 * @pseudo: pseudo struct
 *
 * Return: 0 on success,
 *         1 if inbuilt cmd found but fails,
 *         -2 if inbuilt cmd signals exit(),
 *         -1 if inbuilt cmd not found
 */
int execinbuilt(pseudo_t *pseudo)
{
	int i, inbuilt_ret = -1;
	inbuilt_cmd inbuiltcmds[] = {
		{"exit", "cause the shell to exit", _exit},
		{"env", "prints the current environment", penv},
		{"help", "display information about inbuilt commands", _help},
		{"history", "display the command history list with line numbers", _history},
		{"setenv", "add or change environment variable", __setenv},
		{"unsetenv", "remove an environment variable", __unsetenv},
		{"cd", "change the working directory", _cd},
		{"alias", "define or display aliases", _alias},
		{NULL, NULL}};

	i = chkinbuilt(pseudo);
	if (i < 0)
		return (inbuilt_ret);
	inbuilt_ret = inbuiltcmds[i].function(pseudo);
	return (inbuilt_ret);
}