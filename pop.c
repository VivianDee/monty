#include "monty.h"
/**
  * pop - A function frees the value at the top of the stack
  * @stack: A pointer to the stack
  * @line_number: The morty bytescode's line number
  *
  */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(*stack);
		free(buffer.code);
		fclose(buffer.file);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if ((*stack) != NULL)
		(*stack)->prev = NULL;
	free(top);
	top = NULL;
}
