#include "main.h"
#include <stdarg.h>

/**
 * print_unsigned - Prints an unsigned number to the stdout
 * @types: List a of arguments variadic agruments
 * @buffer: Buffer size array to handle print
 * @flags:  finds the active flags
 * @width: get width of the input
 * @precision: specification of precision
 * @size: Size specifier
 * Return: count of chars
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned number in base 8
 * @types: Lista of arguments in the va_list
 * @buffer: Buffer size
 * @flags:  finds all the active flags
 * @width: gets width of the input
 * @precision: Precision specification
 * @size: Size of specifier
 * Return: count of the chars
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned number in base 16
 * @types: List of variadic arguments
 * @buffer: Buffer size of arrays
 * @flags: flags any active files
 * @width: gets width of the input
 * @precision: precisons specification
 * @size: Size of the specifier
 * Return: Count of Chars
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Print s number in upper base 16 haxadecimal
 * @types: variadic arguments list
 * @buffer: Buffer size
 * @flags: flag any flags found
 * @width: finds the width of input
 * @precision: Precision specificity
 * @size: specifiers size
 * Return: counts of  char
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Print s number in upper base 16 haxadecimal
 * @types: variadic arguments list
 * @buffer: Buffer size
 * @flags: flag any flags found
 * @width: finds the width of input
 * @precision: Precision specificity
 * @size: specifiers size
 * @flag_ch: flags any flags
 * @map_to: mapping of the various cacharacters
 * Return: counts of char in stdout
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
