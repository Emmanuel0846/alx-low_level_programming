#include "main.h"


/**
 * _isalpha - entry point
 *
 * Description: function that checks for alphabetic character
 *
 * @c:character to check if it islowercase
 *
 * Return: return 1 if lower/uppercase , 0 if not
 *
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
