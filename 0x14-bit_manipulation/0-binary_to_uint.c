#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Entry point to convert a binary number to an unsigned int
 * Project by Olaoluwa Emmanuel IDOWU
 * @b: string containing binary number to be converted
 *
 * Return: unsigned int corresponding to binary number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int myValue = 0;
	int m = 0;

	if (b == NULL)
		return (0);
	while (b[m] != '\0')
	{
		if (b[m] != '0' && b[m] != '1')
			return (0);
		myValue <<= 1;
		myValue += b[m] - '0';
		m++;
	}
	return (myValue);
}
