#include "monty.h"
/**
 * getarg - get the arguments and proccess the file
 * @argv: arguments vecto
 * Return: 0 success otherwise 1
 */
int getarg(char *argv[])
{
	FILE *f = NULL;
	char *line = NULL;
	char *buffer[4096];
	size_t size = 0;
	stack_t *head = NULL;
	unsigned int count = 0;

	f = fopen(argv[1], "r");
	global_stack.file = f;
	global_stack.head = head;
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, f) != -1)
	{
		global_stack.input_line = line;
		count++;
		getbuffer(line, buffer); /* to tokenize the line*/
		if (buffer != NULL)
		{
			if (buffer[0] != '\0' && strcmp("push", buffer[0]) == 0)
				checkdigitpush(buffer[1], count);
			else
				checkdigit(buffer[1], count);
			execute(buffer[0], &head, count);
		}
		else
		{
			count++;
		}
	}
	freestack_t(head);
	free(global_stack.input_line);
	fclose(f);
	exit(EXIT_SUCCESS);
}
/**
 * getbuffer - takes the arguments and save the info in buffer
 * @str: string input
 * @tokens: tokens from string
 */
void getbuffer(char *str, char **tokens)
{
	int i = 0;
	char *t;
	char *separators = " \r\a\t\n";

	if (tokens == NULL)
		exit(EXIT_FAILURE);
	t = strtok(str, separators);
	while (t != NULL && t[0] != '#')
	{
		tokens[i] = t;
		i++;
		token = strtok(NULL, separators);
	}
	tokens[i] = NULL;
}
/**
 * freestack_t - frees memory
 * @head: stack root
 */
void freestack_t(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
