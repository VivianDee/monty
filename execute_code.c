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
		if (strcmp(opcode, "push") == 0 && is_digit(buffer.arg))
			instruction.f = push;
		else if (strcmp(opcode, "pall") == 0)
			instruction.f = pall;
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
			fclose(buffer.file);
			free(buffer.file);
			free(code);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}

		instruction.f(stack, line_num);
	}
	else
	{
		return;
	}
}

/**
  * is_digit- A function that checks if a given string is a number
  * @str: A string
  *
  */

int is_digit(const char *str)
{
	int number = 0;
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			number = (number * 10) + (str[i] - '0');
		else
			return (0);
		i++;
	}
	return (1);
}
