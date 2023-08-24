#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct GlobalData - Holds global variables: argument, file, line content.
 * @arg: Argument value.
 * @line: Input line content.
 * @file: Pointer to the Monty file.
 */
typedef struct GlobalData
{
	char *arg;
	FILE *file;
	char *line;
} glob_t;

extern glob_t glob;

/**
 * struct StackNode - Doubly linked list node for stack/queue.
 * @n: Integer value.
 * @prev: Pointer to the previous element.
 * @next: Pointer to the next element.
 */
typedef struct StackNode
{
	int n;
	struct StackNode *prev;
	struct StackNode *next;
} stack_t;

/**
 * struct Instruction - Opcode and its corresponding function.
 * @opcode: The opcode.
 * @f: Function to handle the opcode.
 */
typedef struct Instruction
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void execute_file(stack_t **stack);
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);

void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);

/* Stack helper functions */
stack_t *add_node(stack_t **stack, const int n);
int is_number(char *str);
void free_stack(stack_t *stack);

#endif /* MONTY_H */
