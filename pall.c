#include "monty.h"
/**
  * pall - A function that prints a stack
  * @stack: A pointer to the given stack
  * @line_number: The morty bytecode's line number
  *
  */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *list = *stack;
	size_t count = line_number;

	while (list != NULL)
	{
		printf("%d\n", list->n);
		list = list->next;
		count++;
	}
}
