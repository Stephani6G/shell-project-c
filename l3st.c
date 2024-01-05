#include "main.h"

/**
 * add_var_nodes - function that  adds a variable at the end
 * of a r_var list
 * @head: head of the linked list
 * @lvar: length of the variable
 * @val: value of the variable
 * @lval: length of the value
 * Return: address of the head
 */
r_vars *add_var_nodes(r_vars **head, int lvar, char *val, int lval)
{
	r_vars *new, *temp;

	new = malloc(sizeof(r_vars));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->value = val;
	new->length_var = lval;

	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}
