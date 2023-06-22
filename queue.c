#include "monty.h"

/**
  * queue - A function add a node at the end of the stack
  * @stack: A pointer to the stack
  *
  */

void queue(stack_t **stack)
{
	stack_t *node = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(stack);
		free(buffer.code);
		fclose(buffer.file);
		exit(EXIT_FAILURE);
	}

	node->n = atoi(buffer.arg);
	node->next = NULL;
	node->prev = NULL;

	if (*stack == NULL)
	{
		*stack = node;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = node;
		node->prev = current;
	}
}
