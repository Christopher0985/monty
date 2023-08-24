#include "monty.h"

/**
 * op_div - Perform division with the second top element divided by the top element.
 * @stack: Double pointer to the head of the stack.
 * @line_num: Current line number within the file.
 */
void op_div(stack_t **stack, unsigned int line_num)
{
	stack_t *temp_node;
	int quotient;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: Stack is too short to perform division\n",
				line_num);
		exit(EXIT_FAILURE);
	}

	temp_node = *stack;
	if (temp_node->n == 0)
	{
		fprintf(stderr, "L%d: Division by zero is not allowed\n",
				line_num);
		exit(EXIT_FAILURE);
	}

	quotient = temp_node->next->n / temp_node->n;
	temp_node->next->n = quotient;
	*stack = temp_node->next;
	free(temp_node);
}
