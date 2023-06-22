#include "monty.h"

/**
  * rotl - A function that rotates the stack by one value
  * @stack: A pointer to the stack
  * @line_number: The morty bytescode's line number
  *
  */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *top = *stack;
	stack_t *next = NULL;
	int len = 0;

	line_number += 0;
	while (last->next != NULL)
	{
		last = last->next;
		len++;
	}
	if (len >= 2)
	{
		next = (*stack)->next;
		last->next = top;
		top->prev = last;
		top->next = NULL;
		*stack = next;
	}
}
