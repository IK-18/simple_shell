#include "shell.h"

/**
 *
 *
 */

int main(int argc, char **argv, char **env)
{
	if (argc > 1)
		argv[1] = NULL;
	prompt(env);
	return (0);
}