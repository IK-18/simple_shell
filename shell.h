#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

void prompt(char **env);
void forkexe(char **argv, char *env[]);
char *_strtok(char *str, const char *delim);
int _strcmp(char *s1, char *s2);
char **chrstrtok(char *str);
char *fchk(char *str);
int ptchk(char *str);
char *_strcat(char *dest, char *src);
int _putchar(char c);
void _puts(char *str);
int _getline(char **lineptr, size_t *n);
void *_memchr(const void *s, int c, size_t n);
void *_memcpy(void *dest, const void *src, size_t n);
int inbuilt(char *str);

#endif /*SHELL_H*/
