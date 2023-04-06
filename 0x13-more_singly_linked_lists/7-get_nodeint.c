#include "lists.h"

/**
 * get_nodeint_at_index - Entry point for function returning the
 * nth node of the list
 * Project by Olaoluwa Emanuel Idowu
 * @head: head nodal
 * @index: index of the nodal
 * Return: list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *this_new = head;
	unsigned int m;

	if (!head)
		return (0);
	for (m = 0; this_new; m++)
	{
		if (i == index)
			return (this_new);
		this_new = this_new->next;
	}
	return (NULL);
}
