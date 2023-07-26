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
	int i = 0, inbuilt_ret = -1;
	inbuilt_cmd inbuiltcmds[] = {
		{"exit", "cause the shell to exit", __exit},
		{"env", "prints the current environment", penv},
		{"help", "display information about inbuilt commands", _help},
		{"history", "display the command history list with line numbers", _history},
		{"setenv", "add or change environment variable", __setenv},
		{"unsetenv", "remove an environment variable", __unsetenv},
		{"cd", "change the working directory", _cd},
		{"alias", "define or display aliases", _alias},
		{NULL, NULL, NULL}};

	while (inbuiltcmds[i].flag)
	{
		if (!_strcmp(pseudo->argv[0], inbuiltcmds[i].flag))
		{
			pseudo->linecount++;
			inbuilt_ret = inbuiltcmds[i].function(pseudo);
			break;
		}
		i++;
	}
	return (inbuilt_ret);
}