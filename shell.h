#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

#define MAX_CMD_LEN 100
#define MAX_ARGS 10

void prompt();
void execmd(char **av, char **env, char **path_list);
char *_strtok(char *str, const char *delim);
int _strcmp(char *s1, char *s2);
char **parse_cmd(char *str);
char **ptchk(char **envp);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
int _putchar(char c);
void _puts(char *str);
ssize_t _getline(char *lineptr, ssize_t *n, int fd);
void *_memchr(const void *s, int c, size_t n);
void *_memcpy(void *dest, const void *src, size_t n);
int inbuilt(char **args, char **env);
int _atoi(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *s);

#endif /*SHELL_H*/
