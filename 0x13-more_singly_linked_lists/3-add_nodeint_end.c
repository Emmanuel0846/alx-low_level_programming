#include "lists.h"

/**
 * add_nodeint_end - Entry point for function add nodal at the end
 * Project by Olaoluwa Emmanuel
 * @head: pointer to struct
 * @n: number
 *
 * Return: list
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *renew = malloc(sizeof(listint_t)), *last = *head;

	if (!renew)
		return (NULL);
	renew->n = n;
	renew->next = NULL;
	if (!(*head))
	{
		*head = renew;
	}
	else
	{
		while (last->next)
			last = last->next;
		last->next = renew;
	}
	return (*head);
}
