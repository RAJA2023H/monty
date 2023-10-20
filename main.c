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
	int i = 0, a;
	char data[MAX_LINES][2][MAX_LEN];
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	init_stack(&my_stack);
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		removeSpacesDoller(buffer);
		token = strtok(buffer, " ");
		line++;
		while (token != NULL)
		{
			found = 0;
			for (a = 0; instructions[a].opcode != NULL; a++)
			{
				if (strcmp(token, instructions[a].opcode) == 0)
				{
					if (strcmp(token, "push") == 0)
					{
						token = strtok(NULL, " ");
						if (token != NULL)
						{
							if (isInteger(token))
							{
								strcpy(data[i][0], instructions[a].opcode);
								strcpy(data[i][1], token);
								i++;
							}
							else
							{
								printf("L%d: usage: push integer\n", line);
								exit(EXIT_FAILURE);
							}
						}
					}
					else
					{
						strcpy(data[i][0], instructions[a].opcode);
						strcpy(data[i][1], "");
						i++;
					}
					found = 1;
					break;
				}
			}
			if (!found)
			{
				printf("L%d: unknown instruction  %s\n", line, token);
				exit(EXIT_FAILURE);
			}
			token = strtok(NULL, " ");
		}
	}

	fclose(fp);
	return (0);
}
