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
	instruction_t instruction;

	opcode = strtok(code, " \t\n");
	buffer.arg = strtok(NULL, " \t\n");

	if (!opcode || opcode[0] == '#')
		return;
	instruction.f = (strcmp(opcode, "push") == 0 && is_digit(buffer.arg)) ? push :
		(strcmp(opcode, "pall") == 0) ? pall :
		(strcmp(opcode, "pint") == 0) ? pint :
		(strcmp(opcode, "pop") == 0) ? pop :
		(strcmp(opcode, "swap") == 0) ? swap :
		(strcmp(opcode, "add") == 0) ? add :
		(strcmp(opcode, "sub") == 0) ? sub :
		(strcmp(opcode, "mul") == 0) ? mul :
		(strcmp(opcode, "div") == 0) ? divi :
		(strcmp(opcode, "mod") == 0) ? mod :
		(strcmp(opcode, "pchar") == 0) ? pchar :
		(strcmp(opcode, "pstr") == 0) ? pstr : NULL;
	if (strcmp(opcode, "nop") == 0)
		return;
	if (instruction.f == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		fclose(buffer.file);
		free(code);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	instruction.f(stack, line_num);
}

/**
  * is_digit- A function that checks if a given string is a number
  * @str: A string
  *
  * Return: 1 if str is a number
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
