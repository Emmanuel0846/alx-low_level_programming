#include "lists.h"

/**
 * delete_nodeint_at_index - Entry point for function that delete a nodal
 * @head: nodal head
 * @index: index
 * Return: integer
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int m = 0;
	listint_t *real = *head;
	listint_t *nodal;

	if (!*head)
		return (-1);
	if (index == 0)
	{
		nodal = *head;
		*head = (*head)->next;
		free(real);
		return (1);
	}
	while (real)
	{
		if (m  == index - 1)
		{
			nodal = real->next;
			real->next = nodal->next;
			free(nodal);
			return (1);
		}
		real = real->next, m++;
	}
	return (-1);
}
