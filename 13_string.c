#include "main.h"
/**
 * print_rot13string - Print a string in rot13.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x, *str, in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",
	     out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int count = 0, i = 0, j;

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";

	while (str[i])
	{
		j = 0;
		while (in[j] && in[j] != str[i])
			j++;

		if (in[j] == str[i])
		{
			x = out[j];
			write(1, &x, 1);
			count++;
		}
		else
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}

		i++;
	}

	return (count);
}

