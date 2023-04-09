#include "main.h"

/**
 * get_bit - Entry point to Get the value of a bit at a given index.
 * Project by Olaoluw Emmanuel IDOWU
 * @n: The bit.
 * @index: The index to get the value at - indices start at 0.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - Value of bit at index.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (siizeof(unsigned long int) * 8))
		return (-1);

	if ((n & (1 << index)) == 0)
		return (0);

	return (1);
}
