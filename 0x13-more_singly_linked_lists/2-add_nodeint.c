#include "lists.h"
/**
 * add_nodeint - Entry point for function to  add new node
 * Project by Olaoluwa Emmanuel
 * @head: pointer
 * @n: integer
 * Return: the list with the new nodal
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *renew = malloc(sizeof(listint_t));


	if (!renew)
		return (NULL);
	renew->n = n;
	renew->next = *head;
	*head = renew;

	return (*head);
}
