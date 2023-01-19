#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct stack_i - struct needed
 * @input_line: input chars
 * @s_number: number
 * @file: file input
 * @head: pointer to structure initial
 * @newnode: pointer to structure end
 * Description: input struct for monty project
 */
typedef struct stack_i
{
	char *input_line;
	int s_number;
	FILE *file;
	stack_t *head;
	stack_t *newnode;
} stack_g;

extern stack_g global_stack;

int getarg(char *argv[]);
int execute(char *op, stack_t **stack, unsigned int line_cnt);

int checkdigit(char *tokens, unsigned int line_cnt);
int checkdigitpush(char *tokens, unsigned int line_cnt);

void getbuffer(char *str, char **tokens);
void freestack_t(stack_t *head);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
#endif /* MONTY_H */
