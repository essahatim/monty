#include "monty.h"

/**
 * addToStack - Adds a node to the stack.
 *
 * @new_node: Pointer to the new node.
 * @line: Line number of the opcode.
 */
void addToStack(stack_t **new_node, __attribute__((unused))unsigned int line)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * pStack - Prints the entire stack.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void pStack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * popTheTop - Removes the top node from the stack.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void popTheTop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		stackError(7, line_number);
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * pTop - Prints the value of the top node of the stack.
 *
 * stack: Pointer to a pointer pointing to the top node of the stack.
 * line_number: Line number of the opcode.
 */
void pTop(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL || *stack == NULL)
		stackError(6, line_number);
	printf("%d\n", (*stack)->n);
}
