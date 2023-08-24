#include "monty.h"

/**
 * op_pall - Print all values currently in the stack.
 * @top: Pointer to the top of the stack.
 * @line_num: Line number associated with the opcode.
 */
void op_pall(stack_t **top, unsigned int line_num)
{
	stack_t *current_node = *top;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
		(void)line_num;
	}
}
