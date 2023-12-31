#include "main.h"

/**
 * add_node_sep_end - function that adds a separator
 * found at the end of a sep_list
 * @head: head of the linked list
 * @seprt: separator found (; | &)
 * Return: address of the head
 */
sep_list *add_node_sep_end(sep_list **head, char seprt)
{
	sep_list *new, *dup;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = seprt;
	new->next = NULL;
	dup = *head;

	if (dup == NULL)
	{
		*head = new;
	}
	else
	{
		while (dup->next != NULL)
			dup = dup->next;
		dup->next = new;
	}

	return (*head);
}

/**
 * fre_sep_list - function that frees a sep_list
 * @head: head of the linked list
 */
void fre_sep_list(sep_list **head)
{
	sep_list *dup;
	sep_list *cur;

	if (head != NULL)
	{
		cur = *head;
		while ((dup = cur) != NULL)
		{
			cur = cur->next;
			free(dup);
		}
		*head = NULL;
	}
}
/**
 * line_node_end - function that  adds a command
 * line at the end of a line_list
 * @head: head of the linked lis.
 * @clin: command line
 * Return: address of the head
 */
line_list *line_node_end(line_list **head, char *clin)
{
	line_list *new, *dup;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	dup = *head;

	if (dup == NULL)
	{
		*head = new;
	}
	else
	{
		while (dup->next != NULL)
			dup = dup->next;
		dup->next = new;
	}

	return (*head);
}

/**
 * free_lin_list - function that frees a line_list
 * @head: head of the linked list
 */
void free_lin_list(line_list **head)
{
	line_list *dup;
	line_list *cur;

	if (head != NULL)
	{
		cur = *head;
		while ((dup = cur) != NULL)
		{
			cur = cur->next;
			free(dup);
		}
		*head = NULL;
	}
}
