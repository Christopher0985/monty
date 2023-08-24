#include "monty.h"

/**
 * op_sub - Perform subtraction of the top element from the second top element
 * in the stack.
 * @top: Double pointer to the stack's head.
 * @line_num: Current line number within the file.
 */
void op_sub(stack_t **top, unsigned int line_num)
{
	int result;
	stack_t *temp_node;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: Unable to subtract, stack too short\n",
				line_num);
		exit(EXIT_FAILURE);
	}
	
	temp_node = *top;
	result = temp_node->next->n - temp_node->n;
	temp_node->next->n = result;
	*top = temp_node->next;
	free(temp_node);
}
