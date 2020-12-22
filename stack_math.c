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
		return;
	}
    result = ((*stack)->n) + ((*stack)->next->n);
    (*stack)->next->n = result;
    pop(stack);
}