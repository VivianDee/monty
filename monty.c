#include "monty.h"
buf_t buffer = {NULL, NULL, NULL};

/**
 * main - Entry point of the Monty program.
 * @argc: The number of command-line arguments.
 * @argv: The command-line arguments.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 *
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	char *code = NULL;
	size_t len = 0;
	int read_chars = 1;
	unsigned int line_num = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer.file = fd;
	while (read_chars > 0)
	{
		code = NULL;
		read_chars = _getline(&code, &len, fd);
		buffer.code = code;
		if (read_chars > 0)
			execute_code(&stack, code, line_num);
		free(code);
		line_num++;
	}
	fclose(fd);
	if (code != NULL)
		free(code);
	free_stack(&stack);
	return (0);
}
