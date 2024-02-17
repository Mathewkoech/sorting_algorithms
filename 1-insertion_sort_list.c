#include "sort.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * insertion_sort_list - sorts a doubly linked list using the Insertion
 *
 * @list: doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *temp2, *swap1, *swap2, *swap1_prev, *swap2_next;
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
				swap1_prev = swap1->prev;
				swap2_next = swap2->next;

				swap1->next = swap2_next;
				swap2->prev = swap1_prev;

				swap1->prev = swap2;
				swap2->next = swap1;

				swap1_prev->next = swap2;
				if (swap2_next)
					swap2_next->prev = swap1;

				swap = true;
				print_list(*list);

				if (swap2->n < swap2->prev->n)
				{
					swap = false;
					temp2 = swap2;

					while (temp2->prev)
					{
						if (temp2->n < temp2->prev->n)
						{
							swap1 = temp2->prev;

							swap1_prev = swap1->prev;
							swap2_next = temp2->next;

							temp2->prev = swap1_prev;
							swap1->next = swap2_next;

							temp2->next = swap1;
							swap1->prev = temp2;

							swap2_next->prev = swap1;
							if (swap1_prev)
								swap1_prev->next = temp2;
							else
								*list = temp2;

							swap = true;
							print_list(*list);
						}
						else
							break;
					}
				}
			}
		}
		if (swap == false)
			temp = temp->next;
	}
}
