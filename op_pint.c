#include "monty.h"

/**
 * op_pint - Display the value at the top of the stack.
 * @top: Pointer to the top of the stack.
 * @line_num: Line number corresponding to the opcode.
 */
void op_pint(stack_t **top, unsigned int line_num)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%d: Unable to pint, stack is empty\n",
				line_num);
		free(glob.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*top)->n);
}

