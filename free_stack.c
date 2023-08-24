#include "monty.h"

/**
 * free_stack - Frees a stack_t linked list.
 * @top: Pointer to the top of the stack.
 */
void free_stack(stack_t *top)
{
    stack_t *current_node;

    while (top != NULL)
    {
        current_node = top;
        top = top->next;
        free(current_node);
    }
}
