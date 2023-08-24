#include "monty.h"

/**
 * op_pop - Remove the top element from the stack.
 * @top: Pointer to the top of the stack.
 * @line_num: Line number associated with the opcode.
 */
void op_pop(stack_t **top, unsigned int line_num)
{
	stack_t *temp_node;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: Unable to pop, the stack is empty\n",
				line_num);
		free(glob.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	temp_node = (*top)->next;
	free(*top);
	*top = temp_node;

	if (*top != NULL)
		(*top)->prev = NULL;
}
