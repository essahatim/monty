#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void openFile(char *file_name);
void readFile(FILE *);
int parsLine(char *buffer, int line_number, int format);
void findFunction(char *, char *, int, int);
void callFunction(op_func, char *, char *, int, int);
int isNumeric(const char *str);

/*Stack operations*/
stack_t *createNode(int num);
void freeNodes(void);
void addToQueue(stack_t **, unsigned int);
void pStack(stack_t **, unsigned int);
void addToStack(stack_t **, unsigned int);
void pTop(stack_t **, unsigned int);
void popTheTop(stack_t **, unsigned int);
void swapNodes(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

/*Math operations with nodes*/
void addNodes(stack_t **, unsigned int);
void subNodes(stack_t **, unsigned int);
void divNodes(stack_t **, unsigned int);
void mulNodes(stack_t **, unsigned int);
void modNodes(stack_t **, unsigned int);

/*String operations*/
void printChar(stack_t **, unsigned int);
void printString(stack_t **, unsigned int);
void rotFirst(stack_t **, unsigned int);
void rotLast(stack_t **, unsigned int);

/*hanlding Errors*/
void fileError(int errorCode, ...);
void stackError(int errorCode, ...);
void stringError(int errorCode, ...);

#endif
