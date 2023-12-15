#include"monty.h"

/**
 * mulNodes - Multiplies the top two elements of the stack.
 *
 * @stack: Pointer to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void mulNodes(stack_t **stack, unsigned int line_number)
{
	int product;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		stackError(8, line_number, "mul");
		return;
	}
	*stack = (*stack)->next;
	product = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * modNodes - Computes the remainder of the division
 * of the top two elements of the stack.
 *
 * @stack: Pointer to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void modNodes(stack_t **stack, unsigned int line_number)
{
	int remainder;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		stackError(8, line_number, "mod");
		return;
	}
	if ((*stack)->n == 0)
	{
		stackError(9, line_number);
		return;
	}
	*stack = (*stack)->next;
	remainder = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = remainder;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
