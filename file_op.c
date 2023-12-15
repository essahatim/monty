#include "monty.h"

/**
 * openFile - Opens a file.
 *
 * @fileName: The file name path.
 */
void openFile(char *fileName)
{
	FILE *fd = fopen(fileName, "r");

	if (fileName == NULL || fd == NULL)
		fileError(2, fileName);
	readFile(fd);
	fclose(fd);
}

/**
 * readFile - Reads a file.
 *
 * @fdl Pointer to the file descriptor.
 */
void readFile(FILE *fd)
{
	int lineNum, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (lineNum = 1; getline(&buffer, &len, fd) != -1; lineNum++)
	{
		format = parsLine(buffer, lineNum, format);
	}
	free(buffer);
}

/**
 * parsLine - Parses a line from the file.
 *
 * @buffer: Line from the file.
 * @lineNum: Line number.
 * @format: Storage format.
 * Return: 0 if the opCode is stack, 1 if queue.
 */
int parsLine(char *buffer, int lineNum, int format)
{
	const char *delim = "\n ";
	char *opCode, *val;

	if (buffer == NULL)
		fileError(4);
	opCode = strtok(buffer, delim);
	if (opCode == NULL)
		return (format);
	val = strtok(NULL, delim);
	if (strcmp(opCode, "stack") == 0)
		return (0);
	if (strcmp(opCode, "queue") == 0)
		return (1);
	findFunction(opCode, val, lineNum, format);
	return (format);
}

/**
 * findFunction - find the appropriate function for the opCode
 * @opcode: opcode
 * @value: argument of opCode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @line: line number
 * if 1 nodes will be entered as a queue.
 */
void findFunction(char *opcode, char *value, int line, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
	{"push", addToStack},
	{"pall", pStack},
	{"pint", pTop},
	{"pop", popTheTop},
	{"swap", swapNodes},
	{"add", addNodes},
	{"sub", subNodes},
	{"div", divNodes},
	{"nop", nop},
	{"mul", mulNodes},
	{"mod", modNodes},
	{"pchar", printChar},
	{"pstr", printStr},
	{"rotl", rotFirst},
	{"rotr", rotLast},
	{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			callFunction(func_list[i].f, opcode, value, line, format);
			flag = 0;
		}
	}
	if (flag == 1)
		fileError(3, line, opcode);
}

/**
 * callFunction - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: String representing the opcode.
 * @val: String representing a numeric value.
 * @line: Line number for the instruction.
 * @format: Format specifier.
 */
void callFunction(op_func func, char *op, char *val, int line, int format)
{
	stack_t *node;
	int flag = 1, i;

	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
			val = val + 1, flag = -1;
		if (val == NULL)
			fileError(5, line);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i] == 0))
			{
				fileError(5, line);
			}
		}
		node = createNode(atoi(val) * flag);
		if (format == 0)
			func(&node, line);
		if (format == 1)
			addToQueue(&node, line);
	}
	else
		func(&head, line);
}
