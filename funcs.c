#include "monty.h"

/**
 *push -Add an item to the stack
 *
 *@arg: Value of the new element/item to be pushed
 *@stack_top: Current topmost element of the stack
 *
 */

void push(int arg, stack_t *stack_top)
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
