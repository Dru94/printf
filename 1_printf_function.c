#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - Create a function that assembles a result according to a format.
 *
 * @format: Function argument.
 *
 * Return: Count.
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int t = 0;
	int count = 0;
	va_list args;
	char c;
	char *s;

	va_start(args, format);
	if (format == NULL)
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
			case 'c':
				c = va_arg(args, int);
				t = write(1, &c, 1);
				count = count + t;
				i = i + 2;
				break;
			case 's':
				s = va_arg(args, char *);
				t = write(1, s, strlen(s));
				count = count + t;
				i = i + 2;
				break;
		}
	}
	va_end(args);
	write(1, "\n", 1);
	return (count);
}
