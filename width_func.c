#include "main.h"

/**
 * calculateWidth - Calculates the width for printing
 * @formattedStr: Formatted string in which to print the arguments.
 * @index: List of arguments to be printed.
 * @argList: list of arguments.
 *
 * Return: width.
 */
int calculateWidth(const char *formattedStr, int *index, va_list argList)
{
	int currIndex;
	int width = 0;

	currIndex = *index + 1;
	while (formattedStr[currIndex] != '\0')
	{
		if (isDigit(formattedStr[currIndex]))
		{
			width *= 10;
			width += formattedStr[currIndex] - '0';
			currIndex++;
		}
		else if (formattedStr[currIndex] == '*')
		{
			currIndex++;
			width = va_arg(argList, int);
			break;
		}
		else
		{
			break;
		}
	}

	*index = currIndex - 1;

	return width;
}

