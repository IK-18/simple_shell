#include "shell.h"

/**
 * _itoa - converts an integer into a string
 * @num: number
 * @base: base
 * @is_unsigned: bool to show if value is unsigned
 *
 * Return: converted string
 */
char *_itoa(long int num, int base, int is_unsigned)
{
	static char *arr;
	static char buf[50];
	char sign, *ptr;
	unsigned long new;

	arr = "0123456789ABCDEF";
	new = num;
	if (is_unsigned == 0 && num < 0)
	{
		new = -num;
		sign = '-';
	}
	ptr = &buf[49];
	*ptr = '\0';
	for (new; new != 0; new /= base)
	{
		*--ptr = arr[new % base];
		new /= base;
	}
	if (sign != NULL)
		*--ptr = sign;
	return (ptr);
}