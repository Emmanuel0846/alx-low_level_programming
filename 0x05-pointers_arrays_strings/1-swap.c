#include "main.h"

/**
 * swap_int - main function
 *
 * @a: first argument to be swaped
 * @b: second argument to be swaped
 *
 * Return: void
 *
 */

void swap_int(int *a, int *b)
{
	int p = *a;
	*a = *b;
	*b = p;

}
