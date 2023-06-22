#include "monty.h"
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
	if (opcode == NULL)
		return;
	if (!opcode || opcode[0] == '#')
		return;
	instruction.f =
		(strcmp(opcode, "push") == 0 && is_digit(buffer.arg, line_num)) ? push :
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
		(strcmp(opcode, "pstr") == 0) ? pstr :
		(strcmp(opcode, "rotr") == 0) ? rotr :
		(strcmp(opcode, "rotl") == 0) ? rotl : NULL;
	if (strcmp(opcode, "nop") == 0)
		return;
	if (strcmp(opcode, "stack") == 0 || strcmp(opcode, "queue") == 0)
	{
		buffer.queue = (strcmp(opcode, "stack") == 0) ? 0 :
			(strcmp(opcode, "queue") == 0) ? 1 : 0;
		return;
	}
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

int is_digit(const char *str, int num)
{
	int number = 0;
	int i = 0;

	if (!str)
	{
		fprintf(stderr, "L%d: usage: push integer\n", num);
		fclose(buffer.file);
		free(buffer.stack);
		free(buffer.code);
		exit(EXIT_FAILURE);
	}
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			number = (number * 10) + (str[i] - '0');
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", num);
		fclose(buffer.file);
		free(buffer.stack);
		free(buffer.code);
		exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}
