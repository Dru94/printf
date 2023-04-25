#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
/**
 * is_format_null - checks if format argument is NULL
 * @format: function argument
 * Return: 0 for success
 */
int is_format_nul(const char *format)
{
        if (format == NULL)
                return (1);
        return (0);
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
        float c;
        int s;
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
                                t = write(1, &c, 1);
                                count = count + t;
                                i = i + 2;
                                break;
                        case 'i':
                                s = va_arg(args, int);
                                t = write(1, &s, 1);
                                count = count + t;
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
