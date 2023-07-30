#include "sort.h"
/**
 * switch_node -> this function switches two nodes of a double linked
 * list
 * @list_head: the head of the list
 * @n_a: the first node
 * @n_b: the second node
 */
void switch_node(listint_t **list_head, listint_t **n_a, listint_t **n_b)
{
	listint_t *n1 = *n_a, *n2 = *n_b;

	if (n2->next)
		n2->next->prev = n1;
	n1->next = n2->next;
	n2->next = n1;
	n2->prev = n1->prev;
	if (n1->prev)
		n1->prev->next = n2;
	else
		*list_head = n2;
	n1->prev = n2;
}

/**
 * cocktail_sort_list -> this is an implementation of cocktail sort algorithm
 *
 * @list: the list of integers
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current, *next, *prev, *end = NULL;

	if (!list || !*list || !(*list)->next)
		return;
	while (swapped)
	{
		current = (*list)->next;
		swapped = 0;
		while (current)
		{
			next = current->next;
			if (current->n < current->prev->n)
			{
				end = !next ? current->prev : NULL;
				switch_node(list, &(current->prev), &current);
				print_list(*list);
				swapped = 1;
			}
			if (next == NULL)
				end = end ? end : current;
			current = next;
		}

		if (!swapped)
			break;
		swapped = 0;
		current = end->prev;
		while (current)
		{
			prev = current->prev;
			if (current->n > current->next->n)
			{
				switch_node(list, &current, &(current->next));
				print_list(*list);
				swapped = 1;
			}
			current = prev;
		}
	}
}
