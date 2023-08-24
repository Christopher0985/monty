#include "monty.h"

/**
 * op_add - Calculate the sum of the top two elements in the stack.
 * @top: Pointer to the top of the stack.
 * @line_num: Line number where the opcode is encountered.
 */
void op_add(stack_t **top, unsigned int line_num)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: Insufficient elements for addition\n",
				line_num);
		free(glob.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	(*top)->next->n += (*top)->n;
	op_pop(top, line_num);
}

