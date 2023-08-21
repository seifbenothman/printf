#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);

	count = count_format(format);

	va_end(args);

	return (count);
}
