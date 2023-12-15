#include "monty.h"

/**
 * fileError - related errors.
 *
 * @errorCode: The error code:
 * (1) => No file or more than one file provided.
 * (2) => Unable to open or read the file.
 * (3) => Invalid instruction in the file.
 * (4) => Memory allocation failure.
 * (5) => Invalid parameter for "push" instruction.
 */
void fileError(int errorCode, ...)
{
	va_list args;
	int line_number;
	char *op_code;

	va_start(args, errorCode);
	switch (errorCode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			line_number = va_arg(args, int);
			op_code = va_arg(args, char *);

			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_code);
			break;
		case 4:
			fprintf(stderr, "Error: Memory allocation failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * stackError - related errors.
 *
 * @errorCode: The error code:
 * (6) => Stack is empty for pint.
 * (7) => Stack is empty for pop.
 * (8) => Stack is too short for operation.
 * (9) => Division by zero.
 */
void stackError(int errorCode, ...)
{
	va_list args;
	int line_number;
	char *op_code;

	va_start(args, errorCode);
	switch (errorCode)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
		case 8:
			line_number = va_arg(args, unsigned int);
			op_code = va_arg(args, char *);

			fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, op_code);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * stringError - related errors.
 *
 * @errorCode: The error code:
 * (10) => Number inside a node is outside ASCII bounds.
 * (11) => Stack is empty.
 */
void stringError(int errorCode, ...)
{
	va_list args;
	int line_number;

	va_start(args, errorCode);

	line_number = va_arg(args, int);

	switch (errorCode)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}
