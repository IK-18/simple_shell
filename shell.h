#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define FAILURE 0
#define SUCCESS 1
#define BUF_SIZE 1024
#define FLUSH '\0'
#define NORM 0
#define OR 1
#define AND 2
#define MULTI_CMD 3
#define HISTORY ".history"
#define MAX_HISTORY 4096
#define PSEUDO                                                                  \
	{                                                                           \
		NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
			0, 0, 0                                                             \
	}

extern char **environ;

/**
 * struct listintstr - a singly linked list
 * @num: number
 * @str: string
 * @next: pointer to the next node
 */

typedef struct listintstr
{
	int num;
	char *str;
	struct listintstr *next;
} list_t;

/**
 * struct pseudo - contains pseudo-arguements to pass into functions in the shell
 * @args: argument string
 * @argv: array of arguments
 * @path: PATH string
 * @argc: argument count
 * @linecount: error line count
 * @err_num: error code
 * @linecount_flag: if 1, count this line of input
 * @fname: filename
 * @env: local copy of environment
 * @environ: copy of environment from LL env
 * @history: history list
 * @alias: alias
 * @env_changed: 1 if environment was changed
 * @status: return status of the last executed command
 * @cmd_buffer: address of pointer to command buffer, 1 if multiple commands
 * @cmd_buffer_type: command type || (or), && (and), ; (multi cmd)
 * @readfd: file directory from which to read line input
 * @histcount: history line number count
 */

typedef struct pseudo
{
	char *args;
	char **argv;
	char *path;
	int argc;
	unsigned int linecount;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buffer;
	int cmd_buffer_type;
	int readfd;
	int histcount;
} pseudo_t;

/**
 * struct inbuilt - contains a flag and function for a inbuilt command
 * @flag: inbuilt command flag
 * @desc: inbuilt command description
 * @function: function to execute
 */
typedef struct inbuilt
{
	char *flag;
	char *desc;
	int (*function)(pseudo_t *);
} inbuilt_cmd;

int __setenv(pseudo_t *pseudo);
int __unsetenv(pseudo_t *pseudo);
int _alias(pseudo_t *pseudo);
int _atoi(char *s);
int _cd(pseudo_t *pseudo);
int _chrcmp(char c, char *delim);
char *_chrdup(char *pth, int start, int stop);
int __exit(pseudo_t *pseudo);
int _free(void **ptr);
ssize_t _get(pseudo_t *pseudo);
char *_getenv(pseudo_t *pseudo, const char *var);
char **_getenviron(pseudo_t *pseudo);
char *_gethistory(pseudo_t *pseudo);
ssize_t _getline(pseudo_t *pseudo, char **lineptr, size_t *n);
int _help(pseudo_t *pseudo);
int _isalpha(int c);
int _iscmd(pseudo_t *pseudo, char *pth);
int _ismulticmd(pseudo_t *pseudo, char *buffer, size_t *curr);
char *_itoa(long int num, int base, int is_unsigned);
void *_memchr(const void *s, int c, size_t n);
void *_memcpy(void *dest, const void *src, size_t n);
char *_memset(char *s, char b, unsigned int n);
void _perror(pseudo_t *pseudo, char *estr);
int _putchar(char c);
void _puts(char *str);
void *_realloc(void *ptr, unsigned int osize, unsigned int nsize);
int _setalias(pseudo_t *pseudo, char *str);
int _setenv(pseudo_t *pseudo, char *prop, char *val);
void _setinfo(pseudo_t *pseudo, char *argv[]);
char *_strcat(char *dest, char *src);
char *_strchr(char *, char);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
int _strlen(const char *s);
char *_strncat(char *dest, char *src, int n);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strncpy(char *dest, char *src, int n);
char **_strtok(char *str, char *delim);
int _unsetalias(pseudo_t *pseudo, char *str);
int _unsetenv(pseudo_t *pseudo, char *prop);
int add_history(pseudo_t *pseudo, char *buffer, int count);
list_t *add_node_end(list_t **list, const char *str, int num);
list_t *add_node(list_t **list, const char *str, int num);
void afree(char **arr);
ssize_t bufcmd(pseudo_t *pseudo, char **buffer, size_t *len);
void chkcmd(pseudo_t *pseudo);
void chkmulticmd(pseudo_t *pseudo, char *buffer, size_t *curr, size_t start, size_t len);
int chkinbuilt(pseudo_t *pseudo);
void clear_info(pseudo_t *pseudo);
void comments(char *buffer);
char *cmdpth(pseudo_t *pseudo, char *pth, char *cmd);
int delete_node_at_index(list_t **head, unsigned int index);
int dprint(int in, int fd);
int eatoi(char *str);
int eputchar(char c);
void eputs(char *str);
void execcmd(pseudo_t *pseudo);
int execinbuilt(pseudo_t *pseudo);
int fdputchar(char c, int fd);
int fdputs(char *str, int fd);
int fill_env(pseudo_t *pseudo);
void free_info(pseudo_t *pseudo, int all);
void free_list(list_t **list);
ssize_t get_index_at_node(list_t *list, list_t *node);
int _history(pseudo_t *pseudo);
int interact(pseudo_t *pseudo);
size_t list_len(const list_t *list);
int loop(pseudo_t *pseudo, char *argv[]);
char **ltoa(list_t *list);
list_t *node_prefix(list_t *list, char *str, char c);
int palias(list_t *node);
int penv(pseudo_t *pseudo);
size_t plist(list_t *list);
size_t plistnum(list_t *list);
size_t pliststr(list_t *list);
char *prefix(const char *str, const char *c);
ssize_t rbuf(pseudo_t *pseudo, char *buffer, size_t *size);
int reorder_history(pseudo_t *pseudo);
int reset_alias(pseudo_t *pseudo);
int reset_string(char **old_string, char *new_string);
int reset_vars(pseudo_t *pseudo);
int rhistory(pseudo_t *pseudo);
void sigBlocker(__attribute__((unused)) int signum);
int whistory(pseudo_t *pseudo);

#endif /* SHELL_H */
