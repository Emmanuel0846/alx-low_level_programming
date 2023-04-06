#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Entry poin for Counting the number of unique nodes
 *                      in a looped listint_t linked list.
 * Project by Olaoluwa Emmanuel Idowu
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *snail, *fox;
	size_t nodal = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	snail = head->next;
	fox = (head->next)->next;

	while (fox)
	{
		if (snail == fox)
		{
			snail = head;
			while (snail != fox)
			{
				nodal++;
				snail = snail->next;
				fox = fox->next;
			}

			snail = snail->next;
			while (snail != fox)
			{
				nodal++;
				snail = snail->next;
			}

			return (nodal);
		}

		snail = snail->next;
		fox = (fox->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe -Entry point for Function that Prints a listint_t
 * list safely.
 * Project by Olaoluwa Emmanuel IDOWU
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodal, index_1 = 0;

	nodal = looped_listint_len(head);

	if (nodal == 0)
	{
		for (; head != NULL; nodal++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index_1 = 0; index_1 < nodal; index_1++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodal);
}
