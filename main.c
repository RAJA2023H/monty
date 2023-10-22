#include "monty.h"
#define MAX_SIZE 1024
#define MAX_LINES 100
#define MAX_LEN 10
/**
* main - monty code interpreter
* @ac: number of arguments
* @av: monty file location
* Return: 0 on success
*/
int main(int ac, char **av)
{
	FILE *fp;
	stack_t *my_stack;
	char buffer[MAX_SIZE], *token;
	unsigned int line = 0;
	int a, found;
	size_t i, len;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	init_stack(&my_stack);
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		removeSpacesDoller(buffer);
		token = strtok(buffer, " \n");
		line++;
		while (token != NULL)
		{
			len = strlen(token);
			for (i = 0; i < len; i++)
			{
				if (!isprint(token[i]))
					token[i] = '\0';
			}
			found = 0;
			for (a = 0; instructions[a].opcode != NULL; a++)
			{
				if (strcmp(token, instructions[a].opcode) == 0)
				{
					if (strcmp(token, "push") == 0)
					{
						token = strtok(NULL, " \n\t\r");
						if (token != NULL)
						{
							if (isInteger(token))
								push(&my_stack, atoi(token));
							else
							{
								fprintf(stderr, "L%d: usage: push integer\n", line);
								exit(EXIT_FAILURE);
							}
						}
						else
						{
							fprintf(stderr, "L%d: missing argument for push\n", line);
							exit(EXIT_FAILURE);
						}
					}
					else
						instructions[a].f(&my_stack, line);
					found = 1;
				}
			}
			if (!found)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
			break;
			token = strtok(NULL, " \t\r\n");
		}
	}

	fclose(fp);
	return (0);
}
