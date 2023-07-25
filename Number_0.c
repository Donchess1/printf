#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    char c = (char)va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char*);
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        count++;
                    }
		    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
                default:
                    putchar(*format);
                    count++;
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

/*int main() {
    _printf("Hello, %s! This is a %c test. The percentage sign: %%\n", "User", 'c');
    return 0;
}*/
