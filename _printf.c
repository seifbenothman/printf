#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
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
	int count = 0;

	char specifier;

	va_start(args, format);

	if (format == NULL)
		return (-1 * count);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			specifier = *format;

			count += handle_specifier(specifier, args);
		}
		else
		{
			char temp[2];

			temp[0] = *format;
			temp[1] = '\0';

			count += write_output(temp);
		}
		format++;
	}

	va_end(args);

	return (count);
}
