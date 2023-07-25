#include "main.h"
/**
 * char_printer - function to print char
 * @data: num of arguments
 * @printArr: storage of array to hold print
 * @flags: to check active flags
 * @w: check width
 * @max: maximum specification of char
 * @size: size of char
 * Return: numbers of printed char
 */
int char_printer(va_list data, char printArr[],
	int flags, int w, int max, int size)
{
	char c = va_arg(data, int);

	return (write_c(c, printArr, flags, w, max, size));
}

/**
 * string_printer - function to print string
 * @data: num of args
 * @printStr: storage of str to hold print
 * @w: width of str
 * @size: size of str
 * @flags: to check active flags
 * @max: maximum specification checker
 * Return: num of strings printed
 */
int string_printer(va_list data, char printStr, int w,
	int size, int max, int flags)
{
	int lenght, i;
	char *str = va_arg(data, char *);

	if (str == NULL)
	{
		str = "(nil)";
		if (max >= 6)
			str = "      ";
	}

	for (lenght = 0; str[lenght] != '\0'; lenght++)
	{
	
	}

	if (max >= 0 && max < lenght)
		lenght = max;
	if (w > lenght)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], lenght);
			for (i = width - lenght; i > 0; i++)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - lenght; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], lenght);
			return (w);
		}
	}
	return (write(1, str, lenght));
}

/**
 * percent_printer - function to print sign percent
 * @data: num of args
 * @printStr: storage to hold element to print
 * @w: width of element
 * @size: size of element
 * @flags: to check active flags
 * @max: maximum specification checker
 * Return: num of element printed
 */ 
int percent_printer(va_list data, char printStr, int w,
	int size, int max, int flags)
{
	return (write(1, "%%", 1));
}

/**
 * integer_printer - function to print integer
 * @data: num of args
 * @printStr: storage to hold element to print
 * @w: width of element
 * @size: size of int
 * @flags: to check active flags
 * @max: maximum specification checker
 * Return: num of int printed
 */
int integer_printer(va_list data, char printStr, int w,
	int size, int max, int flags)
{
	int i = storage - 2;
	int not_int = 0;
	long int l = va_arg(data, long int);
	unsigned long int n;

	l = chng_size(l, size);

	if (l == 0)
		data[i--] = '0';

	data[storage - 1] = '\0';
	n = (unsigned long int)l;

	if (; < 0)
	{
		n = (unsigned long int)((-1) * n);
		not_int = 1;
	}

	for (; num > 0; num /= 10)
	{
		data[i--] = (num % 10) + '0';
	}

	i++;

	return (int_write(not_int, i, data, w, size, max, flags)
}

/**
 * binary_printer - function to print size_t num
 * @data: num of args
 * @printStr: storage to hold element to print
 * @w: width of element
 * @size: size of element
 * @flags: to check active flags
 * @max: maximum specification checker
 * Return: num of int printed
 */
int binary_printer(va_list data, char printStr, int w,
	int size, int max, int flags)
{
	size_t i, j, k, sum;
	size_t n[32];
	int count;

	i = va_arg(data, size_t);
	j = 2147483648; /* (2 ^ 31) */
	n[0] = i / j;

	k = 1;
	while (k < 32)
	{
		j /= 2;
		n[i] = (i / j) % 2;
		i++;
	}

	k =0;
	sum = 0;
	count = 0;
	while (i < 32)
	{
		sum += n[k];
		if (sum || k == 31)
		{
			char z = '0' + n[k];
			write(1, &z, 1);
			count++;
		}
		k++;
	}
	return (count);
}
