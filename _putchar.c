#include <unistd.h>
/**
 * _putchar - Function writes to standard output.
 *
 * @c: Function argument.
 */
int _putchar(char c)
{

	return (write(1, &c, 1));

} 
