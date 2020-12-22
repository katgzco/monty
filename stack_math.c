#include "monty.h"

void add(stack_t **stack, unsigned int ln)
{
	char *msg = NULL;
	int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		msg = _itoa(ln);
		man_er(2, "L", msg, ": can't add, stack too short");
		free(msg);
		nodo_ini = "Error";
		return;
	}
	result = ((*stack)->n) + ((*stack)->next->n);
	(*stack)->next->n = result;
	pop(stack, ln);
}

void div(stack_t **stack, unsigned int ln)
{
	char *msg = NULL;
	int result = 0;

	msg = _itoa(ln);
	if (*stack == NULL || (*stack)->next == NULL)
	{
		man_er(2, "L", msg, ": can't div, stack too short");
		free(msg);
		nodo_ini = "Error";
		return;
	}
	if ((*stack)->n == 0)
	{
		man_er(2, "L", msg, ": division by zero");
		free(msg);
		nodo_ini = "Error";
		return;
	}
	result = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, ln);
}