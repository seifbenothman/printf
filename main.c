#include "main.h"
#include <unistd.h>

/**
 *  * _printf - Produces output according to a format.
 *   * @format: The format string.
 *    * @...: Additional arguments based on format specifiers.
 *     *
 *      * Return: The number of characters printed.
 *       */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str_arg;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					/* Print a character */
					{
						int c = va_arg(args, int);
						write(1, &c, 1);
						count++;
					}
					break;

				case 's':
					/* Print a string */
					{
						str_arg = va_arg(args, char *);
						while (*str_arg)
						{
							write(1, str_arg, 1);
							str_arg++;
							count++;
						}
					}
					break;

				case '%':
					/* Print a '%' character */
					write(1, format, 1);
					count++;
					break;

				default:
					/* Ignore unsupported format specifiers */
					break;
			}
		}
		else
		{
			/* Print ordinary characters */
			write(1, format, 1);
			count++;
		}

		format++;
	}

	va_end(args);

	return (count);
}
