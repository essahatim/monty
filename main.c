#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: -0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stdfileError, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	freeNodes();
	return (0);
}

/**
 * createNode - Creates a node.
 *
 * @num: Number to go inside the node.
 * Return: Upon success, a pointer to the node or NULL Otherwise.
 */
stack_t *createNode(int num)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
		fileError(4);
	node->next = NULL;
	node->prev = NULL;
	node->num = num;
	return (node);
}

/**
 * freeNodes - Frees nodes in the stack.
 */
void freeNodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * addToQueue - Adds a node to the queue.
 *
 * @newNode: Pointer to the new node.
 * @line: Line number of the opcode.
 */
void addToQueue(stack_t **newNode, unsigned int line)
{
	stack_t *tmp;

	if (newNode == NULL || *newNode == NULL)
		fileError(4);
	if (head == NULL)
	{
	head = *newNode;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *newNode;
	(*newNode)->prev = tmp;
}
