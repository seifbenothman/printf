#include <unistd.h>
#include <stdio.h>
#include "main.h"
#include "functions.h"

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
int print_string(char *str)
{
	int count = 0;

	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}

	return (count);
}
