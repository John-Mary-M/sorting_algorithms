#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *temp;
	listint_t *sorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	while (current != NULL)
	{
		temp = current->next;
		sorted = current->prev;
		while (sorted != NULL && sorted->n > current->n)
		{
			sorted->next = current->next;
			if (current->next != NULL)
				current->next->prev = sorted;
			current->prev = sorted->prev;
			current->next = sorted;
			if (sorted->prev != NULL)
				sorted->prev->next = current;
			else
				*list = current;
			sorted->prev = current;
			sorted = current->prev;
			print_list(*list);
		}
		current = temp;
	}
}
