#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)

#define UNUSED(x) (void)(x)
#define arr_size 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1


int is_printable(char c);
int _printf(const char *format, ...);
int print_pointer(va_list types, char buffer[]);
int append_hexa_code(char c, char buffer[], int offset);
int print_integer(int num);int print_non_printable(va_list types, char buffer[]);
int unsigned_printer(va_list argList, char outputArr[], int activeFlags,
    int outputWidth, int outputPrec, int outputSize);
int octal_printer(va_list argList, char outputArr[], int activeFlags,
    int outputWidth, int outputPrec, int outputSize);
int hexad_printer(va_list argList, char outputArr[], int activeFlags,
        int outputWidth, int outputPrec, int outputSize);
int isupper_hexa(va_list argList, char outputArr[], int activeFlags,
       int outputWidth, int outputPrec, int outputSize);
int hexa_lower(va_list argList, char mapTo[], char outputArr[],
        int activeFlags, char flagCh, int outputWidth, int outputPrec, int outputSize);
int char_printer(va_list data, char printArr[],
        int flags, int w, int max, int size);
int string_printer(va_list data, char printStr, int w,
        int size, int max, int flags);
int integer_printer(va_list data, char printStr, int w,
        int size, int max, int flags);
int binary_printer(va_list data, char printStr, int w,
        int size, int max, int flags);
int percent_printer(va_list data, char printStr, int w,
        int size, int max, int flags);
int calculateWidth(const char *formattedStr, int *index, va_list argList);
int calculateFlags(const char *formattedStr, int *index);
int calculatePrecision(const char *formattedStr, int *currentIndex, va_list argList);
int calculateArgSize(const char *formattedStr, int *currentIndex);


#endif
