#include "main.h"
/**
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
