#include "monty.h"

/**
 * op_pstr - Displays the string starting from the top of the stack,
 *           followed by a new line.
 * @top: Double pointer to the top of the stack.
 * @line_num: Current line number corresponding to the opcode.
 */
void op_pstr(stack_t **top, unsigned int line_num)
{
	stack_t *current_node = *top;
	(void) line_num;

	while (current_node && current_node->n > 0 && current_node->n <= 127)
	{
		printf("%c", current_node->n);
		current_node = current_node->next;
	}
	printf("\n");
}
