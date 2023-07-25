#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
int is_printable(char c);
int _printf(const char *format, ...);
int print_pointer(va_list types, char buffer[]);
int append_hexa_code(char c, char buffer[], int offset);
int print_integer(int num);
#endif
