#include "shell.h"

/**
 * afree - frees an array of strings
 * @arr: array of strings
 *
 * Return: Nothing
 */
void afree(char **arr)
{
	char **tmp = arr;

	if (!arr)
		return;
	while (*arr)
		free(*arr++);
	free(tmp);
}