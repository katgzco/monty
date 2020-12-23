#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: the numbero of arguments.
 * @ln: array of arguments
 * Return: 0 in succes.
*/
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
/**
 * _div - div the top two elements of the list.
 * @stack: the numbero of arguments.
 * @ln: array of arguments
 * Return: 0 in succes.
*/
void _div(stack_t **stack, unsigned int ln)
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
/**
 * sub -  substract the top two elements of the list.
 * @stack: the numbero of arguments.
 * @ln: array of arguments
 * Return: 0 in succes.
*/
void sub(stack_t **stack, unsigned int ln)
{
	char *msg = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		msg = _itoa(ln);
		man_er(2, "L", msg, ": can't sub, stack too short");
		free(msg);
	nodo_ini = "Error";
		return;
	}

	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, ln);
}
