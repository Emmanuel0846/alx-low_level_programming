#include "lists.h"

/**
 * reverse_listint - Entry point for funtion that Reverse the list
 * Project by Olaoluwa Emmanuel IDOWU
 * @head: head of linked list
 *
 * Return: list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *starting = NULL, *next_1;

	while (*head)
	{
		next_1 = (*head)->next_1;
		(*head)->next_1 = starting;
		starting = *head;
		*head = next_1;
	}
	*head = starting;
	return (*head);
}
