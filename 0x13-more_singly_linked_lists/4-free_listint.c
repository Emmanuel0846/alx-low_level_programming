#include "lists.h"

/**
 * free_listint - Entry point for Function free list
 * @head: pointer
 *
 * Return: nothing
 */
void free_listint(listint_t *head)
{
	listint_t *pointer;

	while (head)
	{
		pointer = head;
		head = head->next;
		free(pointer);
	}
}
