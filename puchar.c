#include "main.h"

/**
  * pchar - A function prints the ascii  char of value at the top of the stack
  * @stack: A pointer to the stack
  * @line_number: The morty bytescode's line number
  *
  */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(buffer.code);
		fclose(buffer.file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	if (top->n < 128 && top->n >= 0)
	{
		putchar(top->n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(*stack);
		free(buffer.code);
		fclose(buffer.file);
		exit(EXIT_FAILURE);
	}
}
