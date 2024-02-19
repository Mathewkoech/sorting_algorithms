#include "sort.h"
#include <stdbool.h>

/**
 * forward_swap - swaps in forward direction
 * @swap1: 1st value
 * @swap2: 2nd value
 */

void forward_swap(listint_t *swap1, listint_t *swap2)
{
	listint_t *swap1_prev, *swap2_next;

	swap1_prev = swap1->prev;
	swap2_next = swap2->next;

	swap1->next = swap2_next;
	swap2->prev = swap1_prev;

	swap1->prev = swap2;
	swap2->next = swap1;

	swap1_prev->next = swap2;
	if (swap2_next)
		swap2_next->prev = swap1;
}

/**
 * back_swap - swaps in backward direction
 * @list: linked list of integers
 * @node: node to be checked
 */

void back_swap(listint_t **list, listint_t *node)
{
	listint_t *swap1_prev, *swap2_next, *swap1;

	swap1 = node->prev;
	swap1_prev = swap1->prev;
	swap2_next = node->next;

	node->prev = swap1_prev;
	swap1->next = swap2_next;

	node->next = swap1;
	swap1->prev = node;

	swap2_next->prev = swap1;
	if (swap1_prev)
		swap1_prev->next = node;
	else
		*list = node;
}

/**
 * back_swapping - swaps backwards
 * @list: linked list of integers
 * @node: node in list
 * Return: bool swap
 */

bool back_swapping(listint_t **list, listint_t *node)
{
	bool swap = false;

	while (node->prev)
	{
		if (node->n < node->prev->n)
		{
			back_swap(list, node);

			swap = true;
			print_list(*list);
		}
		else
			break;
	}

	return (swap);
}

/**
 * insertion_sort_list - sorts a doubly linked list using the Insertion
 *
 * @list: doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *temp2, *swap1, *swap2;
	bool swap;

	temp = *list;
	while (temp)
	{
		swap = false;
		swap1 = temp;
		if (temp->next)
		{
			swap2 = swap1->next;
			if (swap1->n > swap2->n)
			{
				forward_swap(swap1, swap2);

				swap = true;
				print_list(*list);

				if (swap2->n < swap2->prev->n)
				{
					swap = false;
					temp2 = swap2;

					swap = back_swapping(list, temp2);
				}
			}
		}
		if (swap == false)
			temp = temp->next;
	}
}
