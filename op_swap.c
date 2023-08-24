#include "monty.h"

/**
 * op_swap - Swap the positions of the top two elements of the stack.
 * @top: Pointer to the top of the stack.
 * @line_num: Line number associated with the opcode.
 */
void op_swap(stack_t **top, unsigned int line_num)
{
	stack_t *temp_node;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: Unable to swap, stack too short\n",
				line_num);
		free(glob.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	temp_node = (*top)->next;
	(*top)->next = temp_node->next;

	if (temp_node->next != NULL)
		temp_node->next->prev = *top;

	temp_node->prev = NULL;
	temp_node->next = *top;
	(*top)->prev = temp_node;
	*top = temp_node;
}
