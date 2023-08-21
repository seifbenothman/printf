#include <unistd.h>
#include <stdio.h>
#include "main.h"
#include "functions.h"

/**
 * print_number - Print a positive integer to the standard output
 * @n: The integer to be printed
 * Return: The number of characters printed
 */
int print_number(unsigned int n)
{
	int count = 0;
	if (n / 10)
		count += print_number(n / 10);
	count += print_char(n % 10 + '0');
	return (count);
}

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
int print_string(const char *str)
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
int count_format(const char *format, va_list args)
{
	int count = 0;

	while (*format)
	{
		if (*format++ == '%')
		{
			switch (*format++)
			{
			case 'd':
			case 'i':
			{
			int num = va_arg(args, int);
			if (num < 0) {
			count += print_char('-');
			num = -num;
			}
			count += print_number(num);
			}
			break;
			case 'c':
			case '%':
			count++;
			break;
			case 's':
			count += print_string((char *)format);
			while (*format && (*format == 'c' || *format == 's' || *format == '%'))
			{
			format++;
			count++;
			}
			format--;
			break;
			default:
			break;
			}
		}
		else
		{
			count++;
		}
	}

	return (count);
}
