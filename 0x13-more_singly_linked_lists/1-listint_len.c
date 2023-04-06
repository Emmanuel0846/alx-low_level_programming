#include "lists.h"

/**
 * listint_len - Entry point for function return len
 * Project by Olaoluwa Emmanuel
 * @h: pointer
 *
 * Return: size_t leng of the list
 */
size_t listint_len(const listint_t *h)
{
	size_t length = 0;

	while (h)
		h = h->next, length++;
	return (length);
}
