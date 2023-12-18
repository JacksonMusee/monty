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
		printf(stderr, "%s file", argv[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	readline(stream);

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

	line = malloc(sizeof(len));
	if (line == NULL)
		exit(EXIT_FAILURE);

	while ((fgets(line, len, stream)) != NULL)
	{
		lnumm++;
		execute(line, lnumm);
	}
}

/**
 *execute - Execute opcodes as read by readline() function
 *
 *@ln: Ponter to the command/opcode
 *@lnum: Line count
 *
 */

void execute(char *ln, int lnum)
{
	char *cmd;
	int arg;
	char *str_arg;
	stack_t *stack_top = NULL;

	cmd = strtok(ln, " \n");

	if (strcmp(cmd, "push") == 0)
	{
		str_arg = strtok(NULL, " \n");
		if (str_arg)
		{
			arg = atoi(str_arg);
			push(arg, stack_top);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", lnum);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(cmd, "pall") == 0)
	{
		pall(stack_top);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lnum, cmd);
		exit(EXIT_FAILURE);
	}
}
