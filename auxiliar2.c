#include "monty.h"

/**
 * is_number - checks if a string is a number.
 * @str: string to be checked.
 * Return: false on error, true on success.
*/
bool is_number(char *str)
{
	int i = 0;

	if (!str)
		return (false);
	while (str[i] != '\0')
	{
		if (str[0] == '-' || (str[i] >= '0' && str[i] <= '9'))
		{
			i++;
			continue;
		}
		else
			return (false);
	}
	if (str[0] == '-' && i == 1)
		return (false);
	return (true);
}
