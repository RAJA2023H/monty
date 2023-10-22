#include "monty.h"
/**
 * nop -  placeholder instruction
 * @stack: mu stack
 * @line_number: integer
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * add - sum two top element
 * @stack: my stack
 * @line_number: integer
 *
 * Return: integer
 * */
void add(stack_t **stack, unsigned int line)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;
	pop(stack, line);
	(*stack)->n = result;
}
