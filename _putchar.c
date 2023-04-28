#include <unistd.h>
/**
 * _putchar - function writes to standard output
 * @c: function argument
 */
int _putchar(char c)
{

	return (write(1, &c, 1));

} 
