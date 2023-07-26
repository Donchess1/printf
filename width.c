#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int width = 0;
	char curr_char;

	while ((curr_char = format[curr_i]) != '\0')
	{
		switch (curr_char)
		{
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			width *= 10;
			width += curr_char - '0';
			curr_i++;
			break;
		case '*':
			curr_i++;
			width = va_arg(list, int);
			goto end_loop;
		default:
			goto end_loop;
		}
	}

end_loop:
	*i = curr_i - 1;

	return (width);
}

