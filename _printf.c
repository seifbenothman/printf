#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = count_format(format);
	va_end(args);

	return (count);
}
