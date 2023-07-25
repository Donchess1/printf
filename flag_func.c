#include "main.h"

/**
 * calculateFlags - Calculates active flags
 * @formattedStr: Formatted string in which to print the arguments
 * @index: take a parameter.
 * Return: Flags:
 */
int calculateFlags(const char *formattedStr, int *index)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, currIndex;
	int flags = 0;
	const char FLAGS_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	currIndex = *index + 1;
	while (formattedStr[currIndex] != '\0')
	{
		for (j = 0; FLAGS_CHARS[j] != '\0'; j++)
		{
			if (formattedStr[currIndex] == FLAGS_CHARS[j])
			{
				flags |= FLAGS_ARRAY[j];
				break;
			}
		}

		if (FLAGS_CHARS[j] == '\0')
			break;

		currIndex++;
	}

	*index = currIndex - 1;

	return flags;
}

