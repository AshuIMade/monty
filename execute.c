#include "monty.h"
/**
 * execute - select the operation and execute them
 * @op: operation
 * @stack: stack root
 * @line_cnt: line number in file
 * Return: 0 success, failure 1
 */
int execute(char *op, stack_t **stack, unsigned int line_cnt)
{
	size_t i;
	instruction_t op_codes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (op == NULL)
	{
		free(op);
		return (0);
	}
	for (i = 0; op_codes[i].opcode != NULL; i++)
	{
		if (strcmp(op_codes[i].opcode, op) == 0)
		{
			op_codes[i].f(stack, line_cnt);
			return (0);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_cnt, op);
	free(global_stack.input_line);
	fclose(global_stack.file);
	exit(EXIT_FAILURE);
}
