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
			if (strcmp(token, "push") == 0)
			{
				strcpy(data[i][0], token);
				token = strtok(NULL, " ");
				if (token != NULL)
				{
					if (isInteger(token))
						strcpy(data[i][1], token);
					else
					{
						printf("L%d: usage: push integer\n", line);
						exit(EXIT_FAILURE);
					}
				}
				i++;
			}
			else if (strcmp(token, "pall") == 0)
			{
				strcpy(data[i][0], token);
				token = strtok(NULL, " ");
				if (token != NULL)
				{
					strcpy(data[i][1], "");
				}
				i++;
			} else
			{
				printf("L%d: unknown instruction  %s\n", line, token);
				exit(EXIT_FAILURE);
			}
			break;
			token = strtok(NULL, " ");
		}
	}
	fclose(fp);
	return (0);
}
