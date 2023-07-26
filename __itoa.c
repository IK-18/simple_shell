#include "shell.h"

/**
 * __itoa - converts an integer into a string
 * @num: number
 * @base: base
 * @is_unsigned: bool to show if value is unsigned
 *
 * Return: converted string
 */
char *__itoa(long int num, int base, int is_unsigned)
{
	static char *arr;
	static char buf[50];
	char sign = 0, *ptr;
	unsigned long int new;

	arr = is_unsigned ? "0123456789abcdef" : "0123456789ABCDEF";
	if (is_unsigned == 0 && num < 0)
	{
		num = -num;
		sign = '-';
	}
	ptr = &buf[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = arr[num % base];
	for (new = num; new != 0; new /= base)
		*--ptr = arr[new % base];
	if (sign)
		*--ptr = sign;
	return (ptr);
}
