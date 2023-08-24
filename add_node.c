#include "monty.h"

/**
 * add_node - Add a new node at the beginning of a stack_t list
 * @top: Double pointer to the top of the stack
 * @value: Value to be stored in the new node
 *
 * Return: Pointer to the newly added node
 */
stack_t *add_node(stack_t **top, const int value)
{
	stack_t *new_element;

	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory\n");
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	new_element->n = value;
	new_element->prev = NULL;

	if (*top == NULL)
		new_element->next = NULL;
	else
	{
		new_element->next = *top;
		(*top)->prev = new_element;
	}
	*top = new_element;

	return (new_element);
}
