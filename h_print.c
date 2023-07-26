#include "main.h"
/**
 * processPrint - Prints an argument based on its type
 * @formattedStr: Formatted string in which to print the arguments.
 * @argList: List of arguments to be printed.
 * @currentIndex: Current index in the formatted string.
 * @outputBuffer: Buffer array to handle print.
 * @activeFlags: Calculates active flags.
 * @outputWidth: Get width.
 * @outputPrecision: Precision specification.
 * @outputSize: Size specifier.
 * Return: 1 or 2;
 */
int processPrint(const char *formattedStr, int *currentIndex, va_list argList,
	char outputBuffer[], int activeFlags, int outputWidth, int outputPrecision, int outputSize)
{
	int i = 0, unknownLength = 0, printedChars = -1;

	typedef struct {
		char fmt;
		int (*fn)(va_list, char[], int, int, int, int);
	} FormatType;

	FormatType fmtTypes[] = {
		{'c', char_printer}, {'s', string_printer}, {'%', percent_printer},
		{'i', integer_printer}, {'d', integer_printer}, {'b', binary_printer},
		{'u', unsigned_printer}, {'o', octal_printer}, {'x', hexad_printer},
		{'X', isupper_hexa}, {'p', printPointer}, {'S', printNonPrintable},
		{'r', printReverse}, {'R', printRot13String}, {'\0', NULL}
	};

	while (fmtTypes[i].fmt != '\0') {
		if (formattedStr[*currentIndex] == fmtTypes[i].fmt) {
			return (fmtTypes[i].fn(argList, outputBuffer, activeFlags, outputWidth, outputPrecision, outputSize));
		}
		i++;
	}

	if (fmtTypes[i].fmt == '\0') {
		if (formattedStr[*currentIndex] == '\0') {
			return (-1);
		}

		unknownLength += write(1, "%%", 1);

		if (formattedStr[*currentIndex - 1] == ' ') {
			unknownLength += write(1, " ", 1);
		} else if (outputWidth) {
			--(*currentIndex);
			while (formattedStr[*currentIndex] != ' ' && formattedStr[*currentIndex] != '%') {
				--(*currentIndex);
			}

			if (formattedStr[*currentIndex] == ' ') {
				--(*currentIndex);
			}
			return (1);
		}

		unknownLength += write(1, &formattedStr[*currentIndex], 1);
		return unknownLength;
	}

	return (printedChars);
}

