#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>

#define UNUSED(x) (void)(x)

int is_printable(char c)
{
    return isprint((unsigned char)c);
}

int append_hexa_code(char c, char buffer[], int offset)
{
    buffer[offset] = '\\';
    buffer[offset + 1] = 'x';
    buffer[offset + 2] = "0123456789ABCDEF"[((unsigned char)c) >> 4];
    buffer[offset + 3] = "0123456789ABCDEF"[((unsigned char)c) & 0xF];
    return 4:
}

int print_non_printable(va_list types, char buffer[])
{
    int i = 0, offset = 0;
    char *str = va_arg(types, char *);

    UNUSED(buffer);

    if (str == NULL)
        return write(1, "(null)", 6);

    while (str[i] != '\0')
    {
        if (is_printable(str[i]))
            buffer[i + offset] = str[i];
        else
            offset += append_hexa_code(str[i], buffer, i + offset);

        i++;
    }

    return write(1, buffer, i + offset);
}
