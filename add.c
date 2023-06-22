#include "monty.h"

/**
  * add - A function adds the two values at the top of the stack
  * @stack: A pointer to the stack
  * @line_number: The morty bytescode's line number
  *
  */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *temp = NULL;
	int len = 0, sum = 0;

	while (top != NULL)
	{
		top = top->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(*stack);
		fclose(buffer.file);
		free(buffer.code);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	top = *stack;
	sum = (top->n) + (temp->n);
	pop(stack, line_number);
	temp->n = sum;

	*stack = temp;
}
