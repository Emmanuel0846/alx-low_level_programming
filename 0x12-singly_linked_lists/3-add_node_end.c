#include <stdlib.h>
#include "lists.h"
#include <string.h>
#include <stdio.h>

/**
 * add_node_end - Adds a new node at the end
 *           of a list_t list.
 * @head: A pointer the head of the list_t list.
 * @str: The string to be added to the list_t list.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new element.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	char *dup;
	int len;
	list_t *new, *this_node;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	dup = strdup(str);
	if (str == NULL)
	{
		free(new);
		return (NULL);
	}

	for (len = 0; str[len];)
		len++;

	new->str = dup;
	new->len = len;
	new->next = NULL;

	if (*head == NULL)
		*head = new;

	else
	{
		this_node = *head;
		while (this_node->next != NULL)
			this_node = this_node->next;
		this_node->next = new;
	}

	return (*head);
}
