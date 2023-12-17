#include "monty.h"

/**
 *
 *
 *
 *
 */

int main(int argc, char **argv)
{
	 FILE *stream;

	if (argc != 2)
	{
		perror("USAGE: monty file\n");
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
 *
 *
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
 *
 *
 *
 */

void execute(char *ln, int lnum)
{
	char *cmd;
	int arg;
	char *str_arg;

	cmd = strtok(ln, " \n");

	if (strcmp(cmd, "push") == 0)
	{
		str_arg = strtok(NULL, " \n");
		if (str_arg)
		{
			arg = atoi(str_arg);
			push(arg);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", lnum, cmd );
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(cmd, "pall") == 0)
	{
		pall(stack_top);
	}
}
