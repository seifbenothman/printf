#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *str);
int count(const char *format);

#endif
