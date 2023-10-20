#include "monty.h"
/**
 * init_stack - initialize my stack
 * @my_stack: stack_t element
 *
 * Return: void
 */
void init_stack(stack_t **my_stack)
{
	*my_stack = NULL;
}
/**
 * create_node - create new node for my stack
 * @data: value to add to node
 *
 * Return: stack_t value
 */
stack_t *create_node(int data)
{
	stack_t *newNode = (stack_t *)malloc(sizeof(stack_t));

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
	if (newNode != NULL)
	{
		newNode->prev = *stack;
		*stack = newNode; /*Update the stack pointer to the new top node*/
	}
	else
		printf("Failed to push data onto the stack\n");
}
/**
 * pall - print all elements of my stack
 * @stack: stack_t
 * @data: value
 *
 * Return: void
 */
void pall(stack_t *stack, unsigned int data)
{
	stack_t *current = stack;
	(void)data;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
