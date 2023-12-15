#include "monty.h"

/**
 * printChar - Prints the ascii value of the top element.
 *
 * @stack: Pointer to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void printChar(stack_t **stack, unsigned int line_number)
{
	int ascii_val;

	if (stack == NULL || *stack == NULL)
	{
		stringError(11, line_number);
		return;
	}
	ascii_val = (*stack)->n;

	if (ascii_val < 0 || ascii_val > 127)
	{
		stringError(10, line_number);
		return;
	}
	printf("%c\n", ascii_val);
}

/**
 * printStr - Prints a string composed of ASCII values.
 *
 * @stack: Pointer to the top node of the stack.
 * @line_num: Line number of the opcode.
 */
void printStr(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *tmp;
	int ascii_val;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		ascii_val = tmp->n;
		if (ascii_val <= 0 || ascii_val > 127)
			break;
		printf("%c", ascii_val);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotFirst - Rotates the first node of the stack to the bottom.
 *
 * @stack: Pointer to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void rotFirst(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotLast - Rotates the last node of the stack to the top.
 *
 * @stack: Pointer to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void rotLast(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}

