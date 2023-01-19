#include "monty.h"
/**
 * push - add node to the stack
 * @stack: new stack
 * @line_cnt: line number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_cnt)
{
	stack_t *new_node;

	(void)line_cnt;
	new_node = malloc(sizeof(stack_i));
	global_stack.newnode = new_node;
	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "Error: malloc failed\n");
		free(global_stack.input_line);
		fclose(global_stack.file);
		exit(EXIT_FAILURE);
	}
	new_node->n = global_satck.s_number;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
}
