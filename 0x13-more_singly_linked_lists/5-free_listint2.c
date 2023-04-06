#include "lists.h"

/**
 * free_listint2 - Funtions that free a list head = NULL
 * Prohect by Olaoluwa
 * @head: pointer
 *
 *Return: nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *tmpos;

	if (!head)
		return;
	while (*head)
	{
		tmpos = *head;
		*head = (*head)->next;
		free(tmpos);
	}
	*head = NULL;
}
