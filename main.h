#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *str);
int count(const char *format);
int count_format(const char *format);

#endif
