#include "main.h"
#include <stdint.h>

/**
 * _printf - Function prints output based on a format.
 *
 * @format: String of character.
 *
 * Return: output chars.
 */

int _printf(const char *format, ...)
{
	int output_chars;
	va_list args;
	forma_t func_list[] =	{
		{"c", handle_char},

		{"s", handle_string},

		{"%", handle_percent},

		{"d", handle_integer},

		{"i", handle_integer},

		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(args, format);
	output_chars = handler(format, func_list, args);
	va_end(args);
	return (output_chars);

}
