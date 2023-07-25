#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include"main.h"
/**
 *print_pointer - prints pointer variable value
 *@types: various possible types of variables to be pointed to
 *@buffer: array of characters
 *Return: pushed_ch
 */
int print_pointer(va_list types, char buffer[])
{
	int length = 2; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	int pushed_ch;
	int ind = 30;

	if (addrs == NULL)
	{
		pushed_ch = write(1, "(nil)", 5);
		return (pushed_ch);
	}

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	ind++;

	pushed_ch = write(1, "0x", 2);
	pushed_ch += write(1, &buffer[ind], 31 - ind);

	return (pushed_ch);
}
