#include "monty.h"
/**
 * swap -  swaps the top two elements of the stack.
 * @stack: the numbero of arguments.
 * @ln: array of arguments
 * Return: 0 in succes.
*/
void swap(stack_t **stack, unsigned int ln)
{
	char *msg = NULL;
	int temp = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		msg = _itoa(ln);
		man_er(2, "L", msg, ": can't swap, stack too short");
		free(msg);
	nodo_ini = "Error";
		return;
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * pchar - prints char element
 * @stack: the numbero of arguments.
 * @ln: array of arguments
 * Return: 0 in succes.
*/
void pchar(stack_t **stack, unsigned int ln)
{
	char *msg = NULL;

	msg = _itoa(ln);
	if (*stack == NULL)
	{
		man_er(2, "L", msg, ": can't pchar, stack empty");
		free(msg);
		nodo_ini = "Error";
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		man_er(2, "L", msg, ": can't pchar, value out of range");
		free(msg);
		nodo_ini = "Error";
		return;
	}
	putchar((*stack)->n);
	putchar('\n');
}

/**
 * pstr - prints char element
 * @stack: the numbero of arguments.
 * @ln: array of arguments
 * Return: 0 in succes.
*/
void pstr(stack_t **stack, unsigned int ln)
{
	stack_t *current;

	(void)ln;
	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	current = *stack;
	while (current && current->n != 0)
	{
		if ((current->n < 0 || current->n > 127))
		{
			putchar('\n');
			return;
		}
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}

/**
 * rotl - rotates a list
 * @stack: the numbero of arguments.
 * @ln: array of arguments
 * Return: 0 in succes.
*/
void rotl(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *s_refini = *stack, *s_reflas = *stack;
	int i = 0;

	for (i = 0; s_reflas->next != NULL; i++)
		s_refini = s_refini->next;

	s_refini = s_refini->next;

	while (i > 0)
	{
		s_reflas->n = s_refini->n;
		i--;
	}
}
