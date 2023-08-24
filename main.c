#include "monty.h"

global_t global_info;

/**
 * main - Starting point of the monty program.
 * @argc: Count of command line arguments.
 * @argv: Array of strings containing command line arguments.
 *
 * Return: 0 upon success, non-zero upon failure.
 */
int main(int argc, char *argv[])
{
	stack_t *stack_top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	global_info.file = fopen(argv[1], "r");
	if (global_info.file == NULL)
	{
		fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	execute_file_instructions(&stack_top);

	fclose(global_info.file);
	free(global_info.line);
	free_stack(stack_top);
	exit(EXIT_SUCCESS);
}
