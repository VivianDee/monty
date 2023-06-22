#include "monty.h"
/**
  * mul - A function multiplies the two values at the top of the stack
  * @stack: A pointer to the stack
  * @line_number: The morty bytescode's line number
  *
  */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *temp = NULL;
	int len = 0, num = 0;

	while (top != NULL)
	{
		top = top->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(buffer.code);
		fclose(buffer.file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	top = *stack;
	num = (top->n) * (temp->n);
	pop(stack, line_number);
	temp->n = num;

	*stack = temp;
}
