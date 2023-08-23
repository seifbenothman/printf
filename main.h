#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int str_len(char *str);
int write_output(char *str);
int handle_specifier(char specifier, va_list args);
int _printf(const char *format, ...);

#endif
