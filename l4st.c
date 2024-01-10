#include "main.h"

/**
 * free_rvar_list - frees a r_var list
 * @head: head of the linked list.
 */
void free_rvar_list(r_vars **head)
{
	r_vars *temp;
	r_vars *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
