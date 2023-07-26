#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    if (format[curr_i] != '.')
        return precision;

    precision = 0;
    curr_i += 1;

    while (format[curr_i] != '\0')
    {
        switch (format[curr_i])
        {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            precision *= 10;
            precision += format[curr_i] - '0';
            curr_i++;
            break;
        case '*':
            curr_i++;
            precision = va_arg(list, int);
            break;
        default:
            goto loop_exit;
        }
    }

loop_exit:
    *i = curr_i - 1;
    return precision;
}

