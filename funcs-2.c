#include "monty.h"

/**
 *add - adds the top two elements of the stack
 *
 *@stack_top: Top of the stack
 *@lnum: Line number f the opcode
 *
 *Return: Pointer to the new top
 */

stack_t *add(stack_t *stack_top, int lnum)
{
	stack_t *new_top;
	int sum;

	if (stack_top == NULL || stack_top->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	sum = stack_top->n + stack_top->prev->n;
	stack_top->prev->n = sum;
	stack_top->prev->next = NULL;
	new_top = stack_top->prev;

	free(stack_top);

	return (new_top);
}
