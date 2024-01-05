#include "main.h"

/**
 * free_sep_list - frees a sep_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_sep_list(sep_l **head)
{
	sep_l *temp;
	sep_l *curr;

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

/**
 * add_line_node_end - adds a command line at the end
 * of a line_list
 * @head: head of the linked list
 * @lineui: command line
 * Return: address of the head
 */
line_l *add_line_node_end(line_l **head, char *lineui)
{
	line_l *new, *temp;

	new = malloc(sizeof(line_l));
	if (new == NULL)
		return (NULL);

	new->lineui = lineui;
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

/**
 * free_line_list - frees a line_list
 * @head: head of the linked list
 */
void free_line_list(line_l **head)
{
	line_l *temp;
	line_l *curr;

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
