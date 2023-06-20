#include "main.h"


/**
  * free_stack - A function that adds a node to the end a stack
  * @head: A pointer to the given stack
  *
  */

void free_stack(stack_t **head)
{
	stack_t *current = *head;
	stack_t *node = NULL;

	while (current != NULL)
	{
		node = current;
		current = current->next;
		free(node);
		node = NULL;
	}
}
