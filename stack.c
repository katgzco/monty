#include "monty.h"

/**
 * push - manages the input file
 * @stack: head of the list.
 * @ln: line number.
 * Return: void.
*/
void push(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *newNode;

	if (nodo_ini == NULL)
	{
		man_er(0, "Error: malloc failed");
		return;
	}

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
		return;
	newNode->n = atoi(nodo_ini);
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->next = *stack;
	if (*stack)
		(*stack)->prev = newNode;
	*stack = newNode;
}

/**
 * pall - manages the input file
 * @stack: head of the list.
 * @ln: line number.
 * Return: void.
*/
void pall(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *current;

	if (!*stack)
		return;

	current = *stack;

	while (current->next)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	printf("%d\n", current->n);
}

/**
 * pint - manages the input file
 * @stack: head of the list.
 * @ln: line number.
 * Return: void.
*/
void pint(stack_t **stack, unsigned int ln)
{
	char *msg = NULL;

	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		msg = _itoa(ln);
		man_er(2, "L", msg, " can't pint, stack empty");
		free(msg);
		nodo_ini = "Error";
		return;
	}
}
