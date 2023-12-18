#include "monty.h"

/**
 *main - Entry point
 *
 *@argc: Command line arguments count
 *@argv: Vector array of command linr arguments
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	 FILE *stream;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	readline(stream);

	fclose(stream);

	return (0);
}

/**
 *readline - Read a line from input stream and process it
 *
 *@stream: input stream
 *
 */
void readline(FILE *stream)
{
	char *line;
	size_t len = 256;
	int lnumm = 0;
	stack_t *stack_top = NULL;

	line = malloc(sizeof(len));
	if (line == NULL)
		exit(EXIT_FAILURE);

	while ((fgets(line, len, stream)) != NULL)
	{
		lnumm++;
		stack_top = execute(line, lnumm, stack_top);
	}

	free(line);
}

/**
 *execute - Execute opcodes as read by readline() function
 *
 *@ln: Ponter to the command/opcode
 *@lnum: Line count
 *@stack_top: Pointer to stack
 *
 * Return: Pointer to stack
 */

stack_t *execute(char *ln, int lnum, stack_t *stack_top)
{
	char *cmd;

	cmd = strtok(ln, " \n");

	if (strcmp(cmd, "push") == 0)
	{
		stack_top = push(stack_top, ln, lnum);
	}
	else if (strcmp(cmd, "pall") == 0)
	{
		pall(stack_top);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lnum, cmd);
		free(ln);
		exit(EXIT_FAILURE);
	}

	return (stack_top);
}
