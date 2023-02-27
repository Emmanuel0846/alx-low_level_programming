#include "main.h"

/**
 * _strlen - finds the lengh of strings
 *
 * @s:String pointer to the string whose length is to be found
 *
 * Return: returns the lengh of the string
 *
 */

int _strlen(char *s)
{
	int p = 0;
	/*incremeant up to when the last character is NULL,\0*/
	while (*(s + p) != 0)
	{
		p++;
	}
	return (p);
}
