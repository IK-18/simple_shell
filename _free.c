#include "shell.h"

/**
 * _free - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 on success, otherwise 0.
 */
int _free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (SUCCESS);
	}
	return (FAILURE);
}