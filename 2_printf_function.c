#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * is_format_null - Function which checks if format argument is NULL.
 * 
 * @format: Function argument.
 *
 * Return: 0 for success.
 */
int is_format_null(const char *format)
{
	if (format == NULL)
		return (1);
	return (0);
}
/**
 * int_to_string - The function converts integer to string.
 *
 * @num: The integer to be converted.
 *
 * Return: String.
 */
char *int_to_string(int num)
{
	int i = 0;
	int j = 0;
	char temp;
	char *str = malloc(20 * sizeof(char));

	if (num < 0)
	{
		num = -num;
		str[j++] = '-';
	}

	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num);
	str[i] = '\0';
	for (j = 0; j < i / 2; j++)
	{
		temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}
	return (str);
}
/**
 * _printf - Create a function that assembles a result according to a format.
 *
 * @format: Function argument.
 *
 * Return: Count.
 */
int _printf_d(const char *format, ...)
{
	int i = 0;
	int t = 0;
	int count = 0;
	va_list args;
	int c = 0;
	char *result;
	int is_null;

	va_start(args, format);
	is_null = is_format_nul(format);
	if (is_null)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
		{
			t = write(1, &format[i], 1);
			count = count + t;
			i++;
			continue;
		}
		switch (format[i + 1])
		{
			case 'd':
				c = va_arg(args, int);
				result = int_to_string(c);
				t = write(1, &result, _strlen(result));
				count = count + t;
				free(result);
				i = i + 2;
				break;
			case 'i':
				c = va_arg(args, int);
				result = int_to_string(c);
				t = write(1, &result, 1);
				count = count + t;
				free(result);
				i = i + 2;
				break;
			default:
				t = write(1, &format[i], 1);
				count = count + t;
				i = i + 2;
				break;
		}
	}
	va_end(args);
	return (count);
}
