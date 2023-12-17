#include "monty.h"

/**
 *
 *
 *
 *
 */

void push(int arg)
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
 *
 *
 *
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
