#include "monty.h"
/**
 * check_digit_push - checks if data is an integer
 * @tokens: a token
 * @line_cnt: the number of lines
 * Return: 0 if true, 1 if was converted
 */
int check_digit_push(char *tokens, unsigned int line_cnt)
{
	int i = 0;

	if (tokens == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_cnt);
		free(global_stack.input_line);
		fclose(global_stack.file);
		free_stack_t(global_stack.newnode);
		exit(EXIT_FAILURE);
	}
	if (tokens[i] == '-')
		i++;
	for (; tokens[i] != '\0'; i++)
	{
		if (tokens[i] < '0' || tokens[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_cnt);
			free(global_stack.input_line);
			fclose(global_stack.file);
			freestack_t(global_stack.newnode);
			exit(EXIT_FAILURE);
		}
	}
	global_stack.s_number = atoi(tokens);
	return (1);
}
