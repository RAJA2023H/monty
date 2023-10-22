#ifndef MAIN_H
#define MAIN_H

#include <ctype.h>
#include <fcntl.h>  /*file manipulation*/
#include <stdbool.h>/**booleen value*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

void removeSpacesDoller(char *str);
int check_op(char *op, stack_t *my_stack, unsigned int line,
		unsigned int value);
void init_stack(stack_t **my_stack);
void push(stack_t **stack, unsigned int data);
void pall(stack_t **my_stack, unsigned int data);
stack_t *create_node(int data);
int isInteger(const char *str);
void pint(stack_t **stack, unsigned int data);
void pop(stack_t **stack, unsigned int data);
void swap(stack_t **stack, unsigned int line);
int stackLength(stack_t *top);
void nop(stack_t **stack, unsigned int line_number);
#endif
