#include "main.h"

/**
 * unsigned_printer - Outputs an unsigned number.
 * @argList: List of arguments.
 * @outputArr: Array to handle the printout.
 * @activeFlags: Determines which flags are active.
 * @outputWidth: Specifies the width of the output.
 * @outputPrec: Specifies the precision of the output.
 * @outputSize: Specifies the size of the output.
 * Return: Number of characters printed.
 */
int unsigned_printer(va_list argList, char outputArr[], int activeFlags,
	int outputWidth, int outputPrec, int outputSize)
{
	int i = arr_size - 2;
	unsigned long int num = va_arg(argList, unsigned long int);

	num = chng_int_size(num, outputSize);

	if (num == 0)
		outputArr[i--] = '0';

	outputArr[arr_size - 1] = '\0';

	for (; num > 0; num /= 10)
	{
		outputArr[i--] = (num % 10) + '0';
	}

	i++;

	return (uns_write(0, i, outputArr, activeFlags,
		outputWidth, outputPrec, outputSize));
}

/**
 * octal_printer - Displays an unsigned number in octal notation.
 * @argList: List of arguments.
 * @outputArr: Array to handle the printout.
 * @activeFlags: Determines which flags are active.
 * @outputWidth: Specifies the width of the output.
 * @outputPrec: Specifies the precision of the output.
 * @outputSize: Specifies the size of the output.
 * Return: Number of characters printed.
 */
int octal_printer(va_list argList, char outputArr[], int activeFlags,
	int outputWidth, int outputPrec, int outputSize)
{
	int i = arr_size - 2;
	unsigned long int num = va_arg(argList, unsigned long int);
	unsigned long int initNum = num;

	UNUSED(outputWidth);

	num = chng_int_size(num, outputSize);
	if (num == 0)
		outputArr[i--] = '0';
	outputArr[arr_size - 1] = '\0';

	for (; num > 0; num /= 8)
	{
		outputArr[i--] = (num % 8) + '0';
	}

	if (activeFlags & F_HASH && initNum != 0)
		outputArr[i--] = '0';

	i++;

	return (uns_write(0, i, outputArr, activeFlags, outputWidth, outputPrec, outputSize));
}

/**
 * hexad_printer - Outputs an unsigned number in hexadecimal notation.
 * @argList: List of arguments.
 * @outputArr: Array to handle the printout.
 * @activeFlags: Determines which flags are active.
 * @outputWidth: Specifies the width of the output.
 * @outputPrec: Specifies the precision of the output.
 * @outputSize: Specifies the size of the output.
 * Return: Number of characters printed.
 */
int hexad_printer(va_list argList, char outputArr[], int activeFlags,
	int outputWidth, int outputPrec, int outputSize)
{
	return (_hexa_pri(argList, "0123456789abcdef", outputArr,
		activeFlags, 'x', outputWidth, outputPrec, outputSize));
}

/**
 * isupper_hexa - Displays an unsigned number in uppercase
 * hexadecimal notation.
 * @argList: List of arguments.
 * @outputArr: Array to handle the printout.
 * @activeFlags: Determines which flags are active.
 * @outputWidth: Specifies the width of the output.
 * @outputPrec: Specifies the precision of the output.
 * @outputSize: Specifies the size of the output.
 * Return: Number of characters printed.
 */
int isupper_hexa(va_list argList, char outputArr[], int activeFlags,
	int outputWidth, int outputPrec, int outputSize)
{
	return (_hexa_pri(argList, "0123456789ABCDEF", outputArr,
		activeFlags, 'X', outputWidth, outputPrec, outputSize));
}

/*
 * hexa_lower - Outputs a hexadecimal number in lowercase or uppercase.
 * @argList: List of arguments.
 * @mapTo: Array of values to map the number to.
 * @outputArr: Array to handle the printout.
 * @activeFlags: Determines which flags are active.
 * @flagCh: Flag character.
 * @outputWidth: Specifies the width of the output.
 * @outputPrec: Specifies the precision of the output.
 * @outputSize: Specifies the size of the output.
 * Return: Number of characters printed.
 */
int hexa_lower(va_list argList, char mapTo[], char outputArr[], int activeFlags,
	char flagCh, int outputWidth, int outputPrec, int outputSize)
{
	int i = arr_size - 2;
	unsigned long int num = va_arg(argList, unsigned long int);
	unsigned long int initNum = num;

	UNUSED(outputWidth);

	num = convertSizeUnsigned(num, outputSize);

	if (num == 0)
		outputArr[i--] = '0';

	outputArr[arr_size - 1] = '\0';

	while (num > 0)
	{
		outputArr[i--] = mapTo[num % 16];
		num /= 16;
	}

	if (activeFlags & F_HASH && initNum != 0)
	{
		outputArr[i--] = flagCh;
		outputArr[i--] = '0';
	}

	i++;

	return (uns_write(0, i, outputArr, activeFlags, outputWidth, outputPrec, outputSize));
}

