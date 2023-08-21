#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - Print a character to the standard output
 * @c: The character to be printed
 * Return: The number of characters printed
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Print a string to the standard output
 * @str: The string to be printed
 * Return: The number of characters printed
 */
int print_string(char *str)
{
	int count = 0;

	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}

	return (count);
}

/**
 * count_format - Count the number of characters to be printed for a format
 * @format: The format string
 * Return: The number of characters to be printed
 */
int count_format(const char *format)
{
	va_list args
	va_start(args, format);
	int count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
			count++;
			break;

			case 's':
			count += print_string(va_arg(args, char *));
			break;

			case '%':
			count++;
			break;

			default:
			break;
			}
		}
		else
		{
			count++;
		}

		format++;
	}

	va_end(args);
	return (count);
}
