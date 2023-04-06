#include "lists.h"

/**
 * pop_listint - Entry point for function that deletes the head nodal
 * Projecct by Olaoluwa Emmanuel Idowu
 * @head: head nodal
 *
 * Return: head node’s data
 */
int pop_listint(listint_t **head)
{
	listint_t *this_new = *head;
	int number;

	if (!*head)
		return (0);

	number = (*head)->n;
	*head = this_new->next;
	free(this_new);
	return (number);
}
