#include "main.h"

/**
 * print_int - function that print int
 * @types: Lists of arg
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of int printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[BUFF_SIZE - 2] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	for (i = BUFF_SIZE - 2; num > 0; i--)
	{
		buffer[i] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	write_number(is_negative, i, buffer, flags, width, precision, size);

	return (write(1, &buffer[i], BUFF_SIZE - i - 1));
}

