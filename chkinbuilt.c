#include "shell.h"

/**
 * chkinbuilt - finds an inbuilt command
 * @pseudo: pseudo struct
 *
 * Return: index of command, -1 if not found
 */
int chkinbuilt(pseudo_t *pseudo)
{
	int i, index = -1;
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

	for (i = 0; inbuiltcmds[i].flag; i++)
	{
		if (!_strcmp(pseudo->argv[0], inbuiltcmds[i].flag))
		{
			index = i;
			break;
		}
	}
	return (index);
}