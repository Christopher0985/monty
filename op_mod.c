#include "monty.h"

/**
 * op_mod - Calculate the remainder when dividing the second top element
 * of the stack by the top element of the stack.
 * @top: Pointer to the top of the stack.
 * @line_num: Line number corresponding to the opcode.
 */
void op_mod(stack_t **top, unsigned int line_num)
{
	int divisor, dividend;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: Stack is too short to perform modulus\n",
				line_num);
		exit(EXIT_FAILURE);
	}

	divisor = (*top)->n;
	dividend = (*top)->next->n;

	if (divisor == 0)
	{
		fprintf(stderr, "L%d: Division by zero is not allowed\n",
				line_num);
		exit(EXIT_FAILURE);
	}

	(*top)->next->n = dividend % divisor;
	op_pop(top, line_num);
}
