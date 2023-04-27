#include "main.h"
/**
 * _strlen - Function that calculates the length of string excluding the NULL terminator.
 *
 * @res: Pointer to a string.
 *
 * Return: Count.
 */
int _strlen(char* res)
{
	int i = 0;
	int count = 0;

	while(res[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}
