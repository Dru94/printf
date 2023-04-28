#include "main.h"
/**
 * handler - function to handle arguments
 * @format: function argument
 * @forma_t: function argument
 * @args: function argument
*/
int handler(const char *format, forma_t func_list[], va_list args)
{

	int i;
    int j;
    int z_val; 
    int output_chars = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; func_list[j].symbol != NULL; j++)
			{
				if (format[i + 1] == func_list[j].symbol[0])
				{
					z_val = func_list[j].f(args);
					if (z_val == -1)
						return (-1);
					output_chars += z_val;
					break;
				}
			}
			if (func_list[j].symbol == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					output_chars = output_chars + 2;
				}
				else
                {
					return (-1);
                }
			}
			i = i + 1; 
		}
		else
		{
			_putchar(format[i]); 
			output_chars++;
		}
	}
	return (output_chars);
}
