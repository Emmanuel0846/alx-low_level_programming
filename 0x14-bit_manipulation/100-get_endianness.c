#include "main.h"

/**
 * get_endianness -  Entry point  to Check the endianness.
 *
 * Return: If big-endian - 0.
 *         If little-endian - 1.
 */
int get_endianness(void)
{
	int myValue = 1;
	char *end = (char *)&myValue;

	if (*end == 1)
		return (1);

	return (0);
}
