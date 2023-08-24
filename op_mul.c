#include "monty.h"

/**
 * op_mul - Perform multiplication of the top element with the second element
 * of the stack.
 * @top: Double pointer to the stack's top.
 * @line_num: Current line number in the file.
 */
void op_mul(stack_t **top, unsigned int line_num)
{
	int product;
	stack_t *temp_node;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: Unable to multiply, stack too short\n",
				line_num);
		exit(EXIT_FAILURE);
	}

	temp_node = *top;
	product = temp_node->next->n * temp_node->n;
	temp_node->next->n = product;
	*top = temp_node->next;
	free(temp_node);
}

