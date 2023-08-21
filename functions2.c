#include <unistd.h>
#include <stdio.h>
#include "main.h"
#include "functions.h"

/**
 *count_format - Count the number of characters to be printed for a format
 * @format: The format string
 * Return: The number of characters to be printed
 */
int count_format(const char *format)
{
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
		format++;
		count += print_string(format);
		while (*format)
		{
		if (*format == 'c' || *format == 's' || *format == '%')
		break;
		count++;
		format++;
		}
		format--;
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

	return (count);
}
