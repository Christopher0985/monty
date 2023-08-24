#include "monty.h"

/**
 * op_push - Push an item  onto the stack.
 * @top: Pointer to the top of the stack.
 * @line_num: Current line number corresponding to the opcode.
 */
void op_push(stack_t **top, unsigned int line_num)
{
	int value;

	if (glob.arg == NULL || !is_number(glob.arg))
	{
		fprintf(stderr, "L%d: Usage: push integer\n", line_num);
		free_stack(*top);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}

	value = atoi(glob.arg);
	if (add_node(top, value) == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		free_stack(*top);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_number - Determines if a string represents a valid number.
 * @str: String to check.
 *
 * Return: 1 if the string is a number, 0 otherwise.
 */
int is_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}

	return (1);
}
