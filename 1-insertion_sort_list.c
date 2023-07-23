#include "sort.h"

/**
 * swap_node -> this function swap two nodes in
 * a doubly linked list.
 *
 * @prev_node: the pointer to the previous node
 * @current_node: the pointer to the current node
 * @head: the pointer to the head of the list
 * Return: void
 */

void swap_node(listint_t *prev_node, listint_t *current_node, listint_t **head)
{
	listint_t *aux_node_1 = NULL, *aux_node_2 = NULL;

	if (prev_node == NULL || current_node == NULL)
		return;
	aux_node_1 = prev_node->prev;
	aux_node_2 = current_node->next;

	if (aux_node_1)
		aux_node_1->next = current_node;
	if (aux_node_2)
		aux_node_2->prev = prev_node;

	prev_node->next = aux_node_2;
	prev_node->prev = current_node;
	current_node->next = prev_node;
	current_node->prev = aux_node_1;

	if (aux_node_1 == NULL)
		*head = current_node;
}

/**
 * insertion_sort_list -> this function that sorts a doubly
 * linked list of integers in ascending order using the
 * Insertion sort algorithm
 *
 * @list: the doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;

	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
		return;

	head = *list;

	while (head)
	{
		prev = head->prev;

		while (prev && prev->n > head->n)
		{
			swap_node(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}
		head = head->next;
	}
}
