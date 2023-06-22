#include "monty.h"
/**
  * push - A function that adds a node to the end a stack
  * @stack: A pointer to the given stack
  * @line_number: The morty bytecode's line number
  *
  */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node = malloc(sizeof(stack_t));

	line_number = line_number + 0;
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(*stack);
		free(buffer.code);
		fclose(buffer.file);
		exit(EXIT_FAILURE);
	}

	node->n = atoi(buffer.arg);
	node->next = *stack;
	node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = node;
	}
	*stack = node;
}
