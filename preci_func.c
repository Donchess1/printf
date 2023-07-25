#include "main.h"

/**
 * calculatePrecision - Determines the precision for printing
 * @formattedStr: Formatted string in which to print the arguments
 * @currentIndex: Index of the current character in the formatted string.
 * @argList: List of arguments.
 *
 * Return: Precision.
 */
int calculatePrecision(const char *formattedStr, int *currentIndex, va_list argList)
{
	int currIndex = *currentIndex + 1;
	int precision = -1;

	if (formattedStr[currIndex] != '.')
		return (precision);

	precision = 0;

	currIndex += 1;
	while (formattedStr[currIndex] != '\0')
	{
		if (isDigit(formattedStr[currIndex]))
		{
			precision *= 10;
			precision += formattedStr[currIndex] - '0';
			currIndex++;
		}
		else if (formattedStr[currIndex] == '*')
		{
			currIndex++;
			precision = va_arg(argList, int);
			break;
		}
		else
		{
			break;
		}
	}

	*currentIndex = currIndex - 1;

	return (precision);
}

