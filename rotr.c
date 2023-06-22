#include "monty.h"

/**
  * rotr - A function that rotates the stack
  * @stack: A pointer to the stack
  * @line_number: The morty bytescode's line number
  *
  */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;
	stack_t *new_list = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	line_number += 0;
	while (*stack != NULL)
	{
		next = (*stack)->next;
		(*stack)->next = new_list;
		(*stack)->prev = NULL;
		new_list = *stack;
		*stack = next;
		if (new_list != NULL)
			new_list->prev = *stack;
	}

	*stack = new_list;
}
