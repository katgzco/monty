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
