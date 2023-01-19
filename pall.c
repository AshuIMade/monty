#include "monty.h"
/**
 * pall - prints the stack
 * @stack: stack head
 * @line_number: line number
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *s = *stack;

	(void)line_number;
	for (; s != NULL; s = s->next)
	{
		printf("%d\n", s->n);
		i++;
	}
}
