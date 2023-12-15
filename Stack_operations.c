#include "monty.h"

/**
 * swapNodes - Swaps the top two elements of the stack.
 *
 * @stack: Pointer to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void swapNodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		stackError(8, line_number, "swap");
		return;
	}

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *stack;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * addNodes - Adds the top two elements of the stack.
 *
 * @stack: Pointer to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void addNodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		stackError(8, line_number, "add");
		return;
	}

	*stack = (*stack)->next;
	result = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * subNodes -  Subtracts the top two elements of the stack.
 *
 * @stack: Pointer to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void subNodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		stackError(8, line_number, "sub");
		return;
	}

	*stack = (*stack)->next;
	result = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divNodes - Divides the top two elements of the stack.
 *
 * @stack: Pointer to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void divNodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		stackError(8, line_number, "div");
		return;
	}
	if ((*stack)->n == 0)
	{
		stackError(9, line_number);
		return;
	}
	*stack = (*stack)->next;
	result = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * @nop - Does nothing.
 *
 * @stack: Pointer to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
