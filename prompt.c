#include "shell.h"
#define MAX_CMD 10

/**
 * prompt - displays a prompt and waits and responds to user input
 * @argv: array containing user input
 * @env: environment variable
 *
 * Return: Nothing
 */

void prompt(char **argv, char **env)
{
	/*handles address of line in *lineptr and size in n within getline*/
	char *lineptr = NULL;
	size_t n = 0;

	/*number of characters read*/
	ssize_t char_len;

	char *av[MAX_CMD];
	pid_t child;

	int status, i, j;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("IKShell$ ");

		char_len = getline(&lineptr, &n, stdin);
		/*frees the pointer after reading characters*/
		if (char_len == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		/*checks for newline character*/
		i = 0;
		while (lineptr[i])
		{
			if (lineptr[i] == '\n')
				lineptr[i] = 0;
			i++;
		}
		/*stores the user input as av*/
		/*looping through each value*/
		j = 0;
		av[j] = strtok(lineptr, " ");
		while (av[j])
		{
			j++;
			av[j] = strtok(NULL, " ");
		}

		/*creates a child process to allow the parent process (prompt)
		still run via execve even though processing user input*/
		child = fork(); /*system call that creates a child process from parent*/
		/*checks return value of fork*/
		if (child == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		if (child == 0)
		{
			/*runs command and checks value simultaneously*/
			if (execve(av[0], av, env) == -1)
				printf("%s: No such file or directory\n", argv[0]);
		}
		/*monitor the status of the child process and wait*/
		else
			wait(&status);
	}
}