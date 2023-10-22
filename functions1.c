#include "monty.h"
/**
 * create_node - create new node for my stack
 * @data: value to add to node
 *
 * Return: stack_t value
 */
stack_t *create_node(int data)
{
	stack_t *newNode = (stack_t *)malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (newNode != NULL)
	{
		newNode->n = data;
		newNode->prev = NULL;
		newNode->next = NULL;
	}
	return (newNode);
}
/**
 * push - add new element to my stack
 * @stack: stack_t
 * @data: value to add
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int data)
{
	stack_t *newNode = create_node(data);
	/*Set the new node's previous pointer to the current top of the stack */
	if (stack == NULL)
	{
		fprintf(stderr, "Error: empty stack\n");
		free(newNode);
		exit(EXIT_FAILURE);
	}
	if (*stack)
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
	}
	else
		newNode->next = NULL;
	newNode->prev = NULL;

	*stack = newNode;
}
/**
 * pall - print all elements of my stack
 * @stack: stack_t
 * @data: value
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int data)
{
	stack_t *current = *stack;
	(void)data;
	while (current != NULL)
	{
		fprintf(stdout,"%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - print the value at the top of the stack without removing it
 * @stack: stack_t
 * @data: value
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int data)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", data);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}
/**
 * pop - remove the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode
 */
void pop(stack_t **stack, unsigned int data)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", data);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->prev;
	free(temp);

	if (*stack != NULL)
	{
		(*stack)->next = NULL;
	}
}
