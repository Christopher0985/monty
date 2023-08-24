#include "monty.h"

/**
 * op_pchar - Print the character at the top of the stack.
 * @top: Pointer to the top of the stack.
 * @line_num: Line number associated with the opcode.
 */
void op_pchar(stack_t **top, unsigned int line_num)
{
	int char_value;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: Unable to pchar, stack is empty\n",
				line_num);
		exit(EXIT_FAILURE);
	}

	char_value = (*top)->n;
	if (char_value < 0 || char_value > 127)
	{
		fprintf(stderr, "L%d: Unable to pchar, value is out of range\n",
				line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", char_value);
}
