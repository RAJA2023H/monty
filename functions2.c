#include "main.h"
/**
 * removeSpacesDoller - removes soaces and dollar signe.
 * @str : the opcode string
 * Return : void.
 *
 */
void removeSpacesDoller(char *str)
{
	int i, j;
	int len = strlen(str);
	int spaceFlag = 0;

	while (len > 0 && str[0] == ' ')
	{
		memmove(str, str + 1, len - 1);
		len--;
	}
	for (i = 0, j = 0; i < len; i++)
	{
		if (str[i] != ' ' && str[i] != '$')
		{
			str[j++] = str[i];
			spaceFlag = 0;
		}
		else
		{
			if (!spaceFlag)
			{
				str[j++] = ' ';
				spaceFlag = 1;
			}
		}
	}
	str[j] = '\0';
}
/**
 * isInteger - chacks if it is an integer
 * @str: opcode string
 *
 * Return: returns the converted string to an integer
 */
int isInteger(const char *str)
{
	char *endptr;

	strtol(str, &endptr, 10);
	return (*endptr == '\0');
}