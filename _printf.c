#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...) {
    int a;
    int pushed_ch = 0;
    va_list args;
    va_start(args, format);

    for (a = 0; format[a]; a++) {
        if (format[a] != '%') {
            write(1, &format[a], 1);
            pushed_ch++;
        } else {
            a++;
            if (format[a] == 'c') {
                char ch = (char)va_arg(args, int);
                write(1, &ch, 1);
                pushed_ch++;
            } else if (format[a] == 'd' || format[a] == 'i') {
                char buffer[20];
                int len = sprintf(buffer, "%d", va_arg(args, int));
                write(1, buffer, len);
                pushed_ch += len;
            } else {
                write(1, &format[a - 1], 1);
                pushed_ch++;
            }
        }
    }

    va_end(args);
    return pushed_ch;
}
