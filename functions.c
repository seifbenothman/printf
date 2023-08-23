#include <unistd.h>
#include <stdio.h>
#include "main.h"
#include "functions.h"
#include <stdarg.h>

/**
 * _printf - Custom printf function that calculates the number
 * of characters to be printed.
 * @format: The format string.
 * Return: The number of characters to be printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = count_format(format, args);
	va_end(args);

	return (count);
}

/**
 * count_format - Counts the number of characters to be printed
 * based on the format string and arguments.
 * @format: The format string.
 * @args: The variable argument list.
 * Return: The number of characters to be printed.
 */
int count_format(const char format, va_list args)
{
	int count = 0;
	const char *ptr = format;

	while (*ptr != '\0')
	{
		if (*ptr != '%')
		{
			count++;
			ptr++;
		}
		else
		{
			ptr++;
			if (*ptr == 's')
			{
				const char *str = va_arg(args, const char *);

				count += print_string(str);
			}
			else if (*ptr == 'd')
			{
				int num = va_arg(args, int);

				count += print_number(num);
			}
			else if (*ptr == 'c')
			{
				char ch = (char)va_arg(args, int);

				count += print_char(ch);
			}
			ptr++;
		}
	}

	return (count);
}
