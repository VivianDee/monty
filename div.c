#include "main.h"

/**
  * divi - A function divides the two values at the top of the stack
  * @stack: A pointer to the stack
  * @line_number: The morty bytescode's line number
  *
  */

void divi(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(buffer.code);
		fclose(buffer.file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	top = *stack;
	if ((top->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(buffer.code);
		fclose(buffer.file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	num = (temp->n) / (top->n);
	pop(stack, line_number);
	temp->n = num;

	*stack = temp;
}
