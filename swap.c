#include "monty.h"
/**
  * swap - A function swap the two values at the top of the stack
  * @stack: A pointer to the stack
  * @line_number: The morty bytescode's line number
  *
  */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *temp = NULL;
	int len = 0;

	while (top != NULL)
	{
		top = top->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(buffer.code);
		fclose(buffer.file);
		free(*stack);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	temp = (*stack)->next;
	top->next = temp->next;
	top->prev = temp;
	temp->next = top;
	temp->prev = NULL;

	*stack = temp;
}
