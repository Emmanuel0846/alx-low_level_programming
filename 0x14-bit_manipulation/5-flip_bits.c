#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to be
 *             flipped to get from one number to another.
 * pROJECT BY oLAOLUWA eMMANUEL iDOWU
 * @n: The number.
 * @m: The number to flip n to.
 *
 * Return: The necessary number of bits to flip to get from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xOr = n ^ m, myBits = 0;

	while (xOr > 0)
	{
		myBits += (xOr & 1);
		xOr >>= 1;
	}

	return (myBits);
}
