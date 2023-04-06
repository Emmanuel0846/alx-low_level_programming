#include "lists.h"

/**
 * sum_listint - Entry point for function sum lists
 * Project by Olaoluwa Emmanuel IDOWU
 * @head: head nodal
 *
 * Return: sums
 */
int sum_listint(listint_t *head)
{
	int sums = 0;

	if (head != NULL)
	{
		while (head->next != NULL)
		{
			sums += head->n;
			head = head->next;
		}
		sums += head->n;
		return (sums);
	}
	return (sums);
}
