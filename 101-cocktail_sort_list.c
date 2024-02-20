#include "sort.h"
#include <stdio.h>

/**
 * node_swap - function to swap two nodes
 * @node1: 1st node
 * @node2: second node
 */

void node_swap(listint_t *node1, listint_t *node2)
{
	listint_t *temp_next, *temp_prev;

	printf("before swap\n");
	printf("node1->next->n: %d\n", node1->next->n);
	printf("node2->prev->n: %d\n", node2->prev->n);

	temp_next = node2->next;
	temp_prev = node1->prev;

	node2->prev = temp_prev;
	node1->next = temp_next;

	node2->next = node1;
	node1->prev = node2;

	printf("after swap\n");
	printf("node1->n: %d\n", node1->n);
	printf("node2->n: %d\n", node2->n);
	printf("node2->next->n: %d\n", node2->next->n);
	printf("node1->prev->n: %d\n", node1->prev->n);

	if (temp_next == NULL)
		return;
	temp_next->prev = node1;

	if (temp_prev == NULL)
		return;
	temp_prev->next = node2;

	printf("after all:\n");
	printf("node1->n: %d\n", node1->n);
	printf("node2->n: %d\n", node2->n);

	printf("temp_next->n: %d\n", temp_next->n);
	printf("temp_prev->n: %d\n\n", temp_prev->n);
}

/**
 * cocktail_sort_list - sorts a doubly linked list using the cocktail
 *
 * @list: doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list, *end, *temp;
	bool swapped = true;

	temp = start;
	while (temp)
	{
		if (!temp->next)
			end = temp;
		temp = temp->next;
	}

	while (swapped)
	{
		swapped = false;

		temp = start;
		while (temp != end)
		{
			if (!temp->next)
			{
				printf("done");
				break;
			}

			if (temp->n > temp->next->n)
			{
				node_swap(temp, temp->next);
				printf("temp->n: %d\n", temp->n);
				swapped = true;
				print_list(*list);
				printf("1\n");
				continue;
			}
			printf("2\n");
			temp = temp->next;
		}

		if (!swapped)
			break;

		swapped = false;

		end = end->prev;

		temp = end->prev;
		while (temp != start || temp == start)
		{
/*			if (!temp->prev)*/
/*				break;*/
			if (temp->n > temp->next->n)
			{
				node_swap(temp, temp->next);
				swapped = true;
				print_list(*list);
			}
			temp = temp->prev;
		}

		start = start->next;
	}
}
