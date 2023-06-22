#include "monty.h"
/**
  * pint - A function prints the value at the top of the stack
  * @stack: A pointer to the stack
  * @line_number: The morty bytescode's line number
  *
  */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(*stack);
		free(buffer.code);
		fclose(buffer.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}
