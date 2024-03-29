#include "sort.h"

/**
 * swap_node_ahead - swaps left to right
 * @current: current node
 * @incoming: current->next
 * @list: linked list
 */

void swap_node_ahead(listint_t *current, listint_t *incoming, listint_t **list)
{
	if (current->prev)
		current->prev->next = incoming;
	else
		*list = incoming;

	if (incoming->next)
		incoming->next->prev = current;
	incoming->prev = current->prev;
	current->next = incoming->next;
	current->prev = incoming;
	incoming->next = current;
}

/**
 * swap_node_behind - swaps right to left
 * @current: current node
 * @incoming: current->prev
 * @list: linked list
 */

void swap_node_behind(listint_t *current, listint_t *incoming, listint_t **list)
{
	if (current->next != NULL)
		current->next->prev = incoming;
	incoming->next = current->next;
	current->prev = incoming->prev;
	if (incoming->prev)
		incoming->prev->next = current;
	else
		*list = current;
	current->next = incoming;
	incoming->prev = current;
	current = incoming;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers 
 *
 * @list: linked list
 */

void cocktail_sort_list(listint_t **list)
{
	bool swapped = true;
	listint_t *start = *list, *end = NULL, *current, *incoming;

	if (!list || !*list || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = false;

		current = start;
		while (current != end)
		{
			if (current->next)
			{
				incoming = current->next;
				if (current->n > incoming->n)
				{
					swap_node_ahead(current, incoming, list);
					swapped = true;
					print_list(*list);
					current = incoming;
					continue;
				}
			}
			current = current->next;
		}

		if (!swapped)
			break;

		swapped = false;
		end = incoming;
		current = end;

		while (current != start)
		{
			if (current->prev)
			{
				incoming = current->prev;
				if (current->n < incoming->n)
				{
					swap_node_behind(current, incoming, list);
					swapped = true;
					print_list(*list);
					current = incoming;
					continue;
				}
			}
			current = current->prev;
		}
		start = incoming;
	}
}
