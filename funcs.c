#include "monty.h"

/**
 *push -Add an item to the stack
 *
 *@stack_top: Current topmost element of the stack
 *@ln: Point to read line
 *@lnum: Line number as it in the file
 *
 * Return: pointer to updatd stack
 */

stack_t *push(stack_t *stack_top, char *ln, int lnum)
{
	char *str_arg;
	int arg;

	str_arg = strtok(NULL, " \n");
	if (str_arg)
	{
		arg = atoi(str_arg);
		if ((strcmp(str_arg, "0") != 0) && arg == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lnum);
			free(ln);
			exit(EXIT_FAILURE);
		}
		else
		{
			stack_t *newnod = malloc(sizeof(stack_t));

			if (newnod == NULL)
			{
				fprintf(stderr, "Error: malloc failed");
				exit(EXIT_FAILURE);
			}
			newnod->n = arg;
			newnod->prev = stack_top;
			newnod->next = NULL;
			stack_top = newnod;
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", lnum);
		free(ln);
		exit(EXIT_FAILURE);
	}

	return (stack_top);
}

/**
 *pall - Print all elements of the stack
 *
 *@stack_top: The last element to added to the stack
 *
 */

void pall(stack_t *stack_top)
{
	stack_t *node = stack_top;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->prev;
	}
}

/**
 *pint - prints the value at the top of the stack
 *
 *@stack_top - Element at the top of stack
 *@lnum: Line number of the opcode
 *
 */
void pint(stack_t *stack_top, int lnum)
{
	if (stack_top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lnum);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", stack_top->n);
}

/**
 *pop - Delete item at the top of stack
 *
 *@stack_top: Point to stack top
 *@lnum: Line number of opcode
 *
 *Return: Point to new stack top
 */

stack_t *pop(stack_t *stack_top, int lnum)
{
	stack_t *temp;

	if(stack_top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lnum);
		exit(EXIT_FAILURE);
	}
	temp = stack_top;
	stack_top = temp->prev;

	free(temp);

	return (stack_top);

}
