#include "lists.h"

/**
 * insert_nodeint_at_index - Entry point function to  insert node
 * Proect by Olaoluwa Emmanuel IDOWU
 * @head: head nodal
 * @idx: index
 * @n: integer
 *
 * Return: listint
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *this_new = malloc(sizeof(listint_t));
	listint_t *actualNodal = *head;
	unsigned int m = 0;

	if (!this_new)
		return (free(this_new), NULL);

	this_new->n = n;
	this_new->next = NULL;

	if (*head == NULL && idx > 0)
	{
		free(this_new);
		return (NULL);
	}

	if (idx == 0)
	{
		this_new->next = *head;
		*head = this_new;
		return (this_new);
	}

	for (; m < idx - 1; m++)
	{
		actualNodal = actualNodal->next;
		if (actualNodal == NULL && idx - m > 0)
		{
			free(this_new);
			return (NULL);
		}
	}

	this_new->next = actualNodal->next;
	actualNodal->next = this_new;

	return (this_new);
}
