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

	opcode = strtok(code, " ");
	argument = strtok(NULL, " ");
	buffer.arg = argument;

	if (opcode)
	{
		if (buffer.arg != NULL && atoi(buffer.arg) && strcmp(opcode, "push") == 0)
			instruction.f = push;
		else if (strstr(opcode, "pall") != NULL)
			instruction.f = pall;
		else
		{
			fprintf(stderr, "L%d: unknown instruction >> %s\n", line_num, opcode);
			exit(EXIT_FAILURE);
		}

		instruction.f(stack, line_num);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		exit(EXIT_FAILURE);
	}
	free(code);
}
