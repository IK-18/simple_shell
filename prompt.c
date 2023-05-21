#include "shell.h"

/**
 * prompt - displays a prompt and waits and responds to user input
 * @argv - array containing user input
 * @environ - environment variable
 *
 * Return - Nothing
 */

void prompt(char **argv, char **environ)
{
    /*handles address of line in *lineptr and size in n within getline*/
    char *lineptr = NULL;
    size_t n = 0;

    /*number of characters read*/
    ssize_t char_len;

    char *av[] = {NULL, NULL};
    pid_t child;

    int status, i = 0;

    while (1)
    {
        printf("IKShell$ ");

        char_len = getline(&lineptr, &n, stdin);
        /*frees the pointer after reading characters*/
        if (char_len == -1)
        {
            free(lineptr);
            exit(EXIT_FAILURE);
        }
        /*checks for newline character*/
        while (lineptr[i])
        {
            if (lineptr[i])
                lineptr[i] = 0;
        }
        /*stores the user input as av*/
        av[0] = lineptr;
        /*creates a child process to allow the parent process (prompt)
        still run via execve even though processing user input*/
        child = fork(); /*system call that creates a child process from parent*/
        /*checks return value of fork*/
        if (child == -1)
        {
            free(lineptr);
            exit(EXIT_FAILURE);
        }
        else if (child == 0)
        {
            /*runs command and checks value simultaneously*/
            if (execve(av[0], av, environ) == -1)
                printf("%s: No such file or directory\n", argv[0]);
        }
        /*monitor the status of the child process and wait*/
        else
            wait(&status);
    }
}