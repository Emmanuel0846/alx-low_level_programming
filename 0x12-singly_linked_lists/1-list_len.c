#include <stddef.h>
#include <stdlib.h>
#include "lists.h"
/**
 * list_len - finds the number of nodes in a list
 * project by Olaoluwa Emmanuel
 * @h: singly linked list
 * Return: number of elements in a linked list
 */
size_t list_len(const list_t *h)
{
	int j;

	for (j = 0; h; j++)
		h = h->next;
	return (j);
}
