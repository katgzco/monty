#include "monty.h"

/**
 * free_opc -copy a string.
 * @array: the array to free
 * @s: the head of the link list
 * @check_file: the file to close.
*/
void free_opc(check *array, stack_t **s, FILE *check_file)
{
	if (array)
		free_arr(array);
	if (*s)
		free_dlistint(*s);
	fclose(check_file);
}
/**
 * copy_string -copy a string.
 * @dest: the string to copye
 * Return: the new string.
*/
char *copy_string(char *dest)
{
	char *str = NULL;
	size_t size = 0;

	if (dest == NULL)
		return (NULL);
	size = strlen(dest);
	str = malloc(size + 1);
	if (str == NULL)
		man_er(0, "Error: malloc failed");
	strcpy(str, dest);
	return (str);
}
/**
 * free_dlistint - frees a list
 * @head: head of the list
*/
void free_dlistint(stack_t *head)
{
	if (!head)
		return;

	while (head->next)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
	head = NULL;
}

/**
 * free_arr - frees a double pointer
 * @array: array to be freed
*/
void free_arr(check *array)
{
	int i = 0;

	while (array[i].opcode)
	{
		free(array[i].opcode);
		if (array[i].arg)
			free(array[i].arg);
		i++;
	}
}

/**
 * man_er - manage the mesagge error
 * @size: the size of the message
 * @mesge: the message to print.
*/
void man_er(int size, const char *mesge, ...)
{
	va_list args;

	va_start(args, mesge);

	char *str = NULL;
	int i = 0;

	fprintf(stderr, "%s", mesge);
	while (i < size)
	{
		str = va_arg(args, char *);
		fprintf(stderr, "%s", str);
		i++;
	}
	fprintf(stderr, "\n");
	va_end(args);
}
