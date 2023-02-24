#include "main.h"

/**
 * _isdigit - Entry point.
 *
 * Description: checks digit.
 *
 * @c: input character.
 *
 * Return: 1 if upper, 0 if not.
 *
 */

int _isdigit(int c);
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
