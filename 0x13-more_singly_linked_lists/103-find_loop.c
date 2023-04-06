#include "lists.h"

/**
 * find_listint_loop - Entry point for Function date
 * Project by Olaoluwa Emmanuel IDOWU
 * @head: Desde main
 *
 * Return: slow_pace
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_pace = head, *fast_pace = head;

	while (slow_pace && fast_pace && fast_pace->next)
	{
		slow_pace = slow_pace->next;
		fast_pace = fast_pace->next->next;
		if (slow_pace == fast_pace)
		{
			slow_pace = head;
			while (slow_pace != fast_pace)
			{
				slow_pace = slow_pace->next;
				fast_pace = fast_pace->next;
			}
			return (slow_pace);
		}
	}
	return (NULL);
}
