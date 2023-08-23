#include <unistd.h>
#include <stdio.h>
#include "main.h"
#include "functions.h"
#include <stdarg.h>

/**
 * str_len - Calculate the length of a string.
 * @str: The input string.
 * Return: The length of the string.
 */
int str_len(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * write_output - Write a string to the standard output
 * @str: The string to be written.
 * Return: The number of characters written.
 */
int write_output(char *str)
{
	int len = str_len(str);

	return (write(1, str, len));
}

/**
 * handle_specifier - Handle different format specifiers
 * @specifier: The format specifier character.
 * @args: The va_list of arguments.
 * Return: The number of characters written.
 */
int handle_specifier(char specifier, va_list args)
{
	int count = 0;
	char c;

	if (specifier == 'c')
	{
		c = (char) va_arg(args, int);

		count += write_output(&c);
	}
	else if (specifier == 's')
	{
		char *str = va_arg(args, char *);

		if (str == NULL)
			str = "(null)";
		count += write_output(str);
	}
	else if (specifier == 'i' || specifier == 'd')
	{
		char buffer[20];

		int n = snprintf(buffer, sizeof(buffer), "%d", va_arg(args, int));

		if (n > 0)
		{
			count += write_output(buffer);
		}
	}
	else
	{
		write(1, "%", 1);

		count += write_output(&c);
	}

	return (count);
}
