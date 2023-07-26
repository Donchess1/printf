#include "main.h"

/**
 * calculateArgSize - Calculates the size to cast the argument
 * @formattedStr: Formatted string in which to print the arguments
 * @currentIndex: Index of the current character in the formatted string.
 *
 * Return: Argument size.
 */
int calculateArgSize(const char *formattedStr, int *currentIndex)
{
	int currIndex = *currentIndex + 1;
	int argSize = 0;

	while (1)
	{
		if (formattedStr[currIndex] == 'l')
			argSize = S_LONG;
		else if (formattedStr[currIndex] == 'h')
			argSize = S_SHORT;

		if (argSize == 0)
			break;

		currIndex++;
	}

	*currentIndex = currIndex - 1;

	return (argSize);
}

