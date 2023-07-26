#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i = *i + 1;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	char curr_char;

	while ((curr_char = format[curr_i]) != '\0')
	{
		switch (curr_char)
		{
		case '-':
		case '+':
		case '0':
		case '#':
		case ' ':
			for (j = 0; FLAGS_CH[j] != '\0'; j++)
			{
				if (curr_char == FLAGS_CH[j])
				{
					flags |= FLAGS_ARR[j];
					break;
				}
			}
			break;
		default:
			goto end_loop;
		}

		curr_i++;
	}

end_loop:
	*i = curr_i - 1;

	return (flags);
}

