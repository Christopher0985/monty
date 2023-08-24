#include "monty.h"

/**
 * read_and_execute_instructions - Read and execute opcodes from a file.
 * @stack: Pointer to the top of the stack.
 */
void execute_instructions(stack_t **stack)
{
	char *current_op = NULL;
	size_t line_buffer_size = 0;
	ssize_t line_read;
	unsigned int line_num = 0;

	while ((line_read = getline(&glob.line, &line_buffer_size,
					glob.file)) != -1)
	{
		line_num++;
		current_op = strtok(glob.line, " \t\r\n\a");
		glob.arg = strtok(NULL, " \n\t");
		if (current_op == NULL || *current_op == '#')
			continue;
		execute_opcode(current_op, stack, line_num);
	}
}

/**
 * perform_opcode_execution - Execute a single opcode.
 * @op: The opcode to be executed.
 * @stack: Pointer to the top of the stack.
 * @line_num: Line number associated with the opcode.
 */
void execute_opcode(char *op, stack_t **stack, unsigned int line_num)
{
	instr_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"nop", op_nop},
		{"add", op_add},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(op, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_num);
			return;
		}
	}

	fprintf(stderr, "L%d: Unknown instruction %s\n", line_num, op);
	free_stack(*stack);
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
}
