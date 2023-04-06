#include "lists.h"

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
 * free_listint_safe - Frees a listint_t list safely (ie.
 *                     can free lists containing loops)
 * @h: A pointer to the address of
 *     the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 *
 * Description: The function sets the head to NULL.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp_1;
	size_t nodal, index_1;

	nodal = looped_listint_count(*h);

	if (nodal == 0)
	{
		for (; h != NULL && *h != NULL; nodal++)
		{
			tmp_1 = (*h)->next;
			free(*h);
			*h = tmp_1;
		}
	}

	else
	{
		for (index_1 = 0; index_1 < nodal; index_1++)
		{
			tmp_1 = (*h)->next;
			free(*h);
			*h = tmp_1;
		}

		*h = NULL;
	}

	h = NULL;

	return (nodal);
}
