#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int print_char(char c);
int print_string(char *str);
int _printf(const char *format, ...);
int count_format(const char *format);

#endif
