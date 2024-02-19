#include "sort.h"
#include <stdbool.h>

/**
 * forward_swap - swaps left to right 
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
 * back_swap - swaps right to left
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
 * back_swapping - calls back swap, if previous node is not NULL
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
 * cocktail_sort_list - sorts a doubly linked list using the cocktail
 *
 * @list: doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp, *start = *list, *end;
	bool swap = true;
	int first_time = 0;

	if (start->next)
	{
		while (swap)
		{
			swap = false;
			temp = start;
			while (temp)
			{
				if (temp->n > temp->next->n)
				{
					forward_swap(temp->next, temp);
					print_list(list);
					swap = true;
				}
				if (!temp->next && first_time == 0)
					end = temp;
				first_time++;
				temp = temp->next;
			}
			start = start->next;

			if (!swap)
				break;

			temp = end->prev;
			swap = back_swapping(list, temp);
			end = end->prev;
		}
	}

	else
		return;
}
