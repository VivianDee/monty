#include "main.h"

/**
  * pstr - A function that prints a string from the stack
  * @stack: A pointer to the stack
  * @line_number: The morty bytescode's line number
  *
  */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	line_number = line_number + 0;

	while (top != NULL)
	{
		if (top->n < 128 && top->n > 0)
		{
			putchar(top->n);
		}
		else
		{
			break;
		}
		top = top->next;
	}
	putchar('\n');
}
