#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a list_t list.
 * project by Olaoluwa Emmanuel
 * @head: A pointer to the list_t list.
 */
void free_list(list_t *head)
{
	list_t *this_node;

	while (head)
	{
		this_node = head->next;
		free(head->str);
		free(head);
		head = this_node;
	}
}
