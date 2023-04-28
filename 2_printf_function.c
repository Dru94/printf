#include "main.h"

/**
 * output_number - The function gets number of characters.
 * 
 * @args: Function argument.
 *
 * Return: len.
 */

int output_number(va_list args)
{
	int j = va_arg(args, int);
	int checker = 1;
	int len = 0;
	unsigned int num;

	if (j < 0)
	{
		len += _putchar('-');
		num = j * -1;
	}
	else
		num = j;

	for (; num / checker > 9; )
    {
		checker *= 10;
    }
	for (; checker != 0; )
	{
		len += _putchar('0' + num / checker);
		num %= checker;
		checker /= 10;
	}
	return (len);
}

/**
 * output_unsigned_num - The function outputs unsigned integer.
 *
 * @k: Function argument.
 *
 * Return: len.
*/
int output_unsigned_num(unsigned int k)
{
	int checker = 1;
	int len = 0;
	unsigned int num = k;

	for (; num / checker > 9; )
    {
		checker *= 10;
    }
	for (; checker != 0; )
	{
		len += _putchar('0' + num / checker);
		num %= checker;
		checker /= 10;

	}
	return (len);
}

/**
 * handle_char - Function displays character to output
 *
 * @args: Function argument.
 *
 * Return: 1.
 */

int handle_char(va_list args)
{
	char val = va_arg(args, int);
	_putchar(val);
	return (1);
}

/**
 * handle_string - Function displays string to output.
 *
 * @args: Function argument.
 *
 * Return: i.
 */

int handle_string(va_list args)
{
	int i;
	const char *s = va_arg(args, const char *);

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
    {
		_putchar(s[i]);
    }
	return (i);
}
/**
 * handle_percent - Function prints % to output.
 *
 * @args: Function argument.
 *
 * Return: 1.
 */
int handle_percent(__attribute__((unused)) va_list args)
{
	_putchar('%');

	return (1);
}
/**
 * handle_integer - Function displays integer to output.
 *
 * @args: Function argument.
 *
 * Return: n.
 */

int handle_integer(va_list args)
{
	int n;
	n = output_number(args);
	return (n);
}
