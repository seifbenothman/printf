#include <limits.h>
#include <stdio.h>
#include "main.h"
#include "functions.h"

/**
 * _printf - Custom printf function that processes format specifiers
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;

	char specifier;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			specifier = *format;
		}
		else
		{
			char temp[2];

			temp[0] = *format;
			temp[1] = '\0';
		}
		format++;
	}

	va_end(args);
	return (count);
}
