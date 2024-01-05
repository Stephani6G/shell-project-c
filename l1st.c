#include "main.h"

/**
 * add_sep_node_end - adds a separator found at the end
 * of a sep_list.
 * @head: head of the linked list
 * @sept: separator found (; | &)
 * Return: address of the head
 */
sep_l *add_sep_node_end(sep_l **head, char sept)
{
	sep_l *new, *temp;

	new = malloc(sizeof(sep_l));
	if (new == NULL)
		return (NULL);

	new->sep = sept;
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
