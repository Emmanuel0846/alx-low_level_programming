#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Entry point to print all the elements of a listint_t list.
 * Project by Olaoluwa Emmanuel
 * @h: A pointer to the head of the list_t list.
 *
 * Return: The number of nodes in the list_t list.
 */
size_t print_listint(const listint_t *h)
{
	size_t num_nodes = 0;

	while (h)
	{
		num_nodes++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (num_nodes);
}
