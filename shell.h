#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void prompt(char **argv, char **env);
void forkexe(char *str, char **argv, char **env);
char *_strtok(char *str, const char *delim);

#endif /*SHELL_H*/
