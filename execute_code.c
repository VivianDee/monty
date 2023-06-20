#include "main.h"

/**
  * execute_code - A function that executes the given opcode
  * @stack: A pointer to the stack
  * @code: A string made up of the opcode and argument
  * @line_num: The morty bytescode's line number
  *
  */

void execute_code(stack_t **stack, char *code, unsigned int line_num)
{
	char *opcode = NULL;
	char *argument = NULL;
	instruction_t instruction;

	opcode = strtok(code, " \t\n");
	argument = strtok(NULL, " \t\n");
	buffer.arg = argument;

	if (opcode)
	{
		if (buffer.arg != NULL && atoi(buffer.arg) && strcmp(opcode, "push") == 0)
			instruction.f = push;
		else if (strstr(opcode, "pall") != NULL)
			instruction.f = pall;
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
			free(code);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}

		instruction.f(stack, line_num);
	}
	else
	{
		free(code);
		free_stack(stack);
		exit(EXIT_SUCCESS);
	}
}
