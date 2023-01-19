#include "monty.h"
/**
 * main - main function.
 * @argc: number of command line arguments.
 * @argv: array containing the program command line arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	getarg(argv);
	return (0);
}
