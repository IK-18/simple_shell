#include "shell.h"

/**
 * main - main function
 * @argc: arguent counter
 * @argv: argument array
 * @env: environment variable
 *
 * Return: 0 on succes, 1 on failure
 */

int main(int argc, char **argv, char **env)
{
	if (argc > 1)
		argv[1] = NULL;
	prompt(env);
	return (0);
}
