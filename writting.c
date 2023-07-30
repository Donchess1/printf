#include "main.h"

/**** WRITE_NUM_FUNC *****/
/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of printed num.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Padding char
 * @extra_c: Extra char
 *
 * Return: Number of printed num.
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, chars_written, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';

	while (prec > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if (extra_c != 0)
		length++;

	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS && padd == ' ') /* Assign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;

			chars_written = write(1, &buffer[ind], length);
			chars_written += write(1, &buffer[1], i - 1);
			return (chars_written);
		}
		else if (!(flags & F_MINUS) && padd == ' ') /* Extra char to left of buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;

			chars_written = write(1, &buffer[1], i - 1);
			chars_written += write(1, &buffer[ind], length);
			return (chars_written);
		}
		else if (!(flags & F_MINUS) && padd == '0') /* Extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;

			chars_written = write(1, &buffer[padd_start], i - padd_start);
			chars_written += write(1, &buffer[ind], length - (1 - padd_start));
			return (chars_written);
		}
	}

	if (extra_c)
		buffer[--ind] = extra_c;

	return (write(1, &buffer[ind], length));
}
