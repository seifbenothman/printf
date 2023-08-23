#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdarg.h>

int str_len(char *str);
int write_output(char *str);
int handle_specifier(char specifier, va_list args);
int _printf(const char *format, ...);

#endif
