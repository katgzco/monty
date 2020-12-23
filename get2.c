#include "monty.h"

/**
 * opc_f - check the match for the function and control it .
 * @idx: the index of the array.
 * @exec: contro the error or execution.
 * @array: struct array to store file inf.
 * @s: the head of the link list.
 * @ln: the num of lines.
 * @opc: struct.
 * Return: the new string.
*/
int opc_f(int idx, bool exec, check *array, stack_t **s, positive ln,
instruction_t *opc)
{
	int i = 0, j = 0, ret = 0;
	char *msg = NULL;

	if (exec == false)
	{
		ret = check_opcode(&array[idx], opc, ln);
		if (ret == 0 || ret == 2)
		{
			if (ret == 0)
			{
				msg = _itoa(ln);
				man_er(3, "L", msg, ": unknown instruction ", array[idx].opcode);
				free(msg);
			}
			return (-1);
		}
	}
	else
	{
		while (array[i].opcode)
		{ j = 0;
			while (opc[j].opcode)
			{
				if ((strcmp(opc[j].opcode, array[i].opcode)) == 0)
				{
					nodo_ini = array[i].arg;
					opc[j].f(s, i);
					if (nodo_ini != NULL && strcmp(nodo_ini, "Error") == 0)
						return (-1);
					break;
				} j++;
			} i++;
		}
	}
	return (0);
}

/**
 * check_opcode - frees a list
 * @element: the name of the function
 * @opc: struct array to store  the function call.
 * @ln: the number of lines read from getline.
 * Return: 0 in succes 1 it no a commando 2 arg isn't int.
*/
int check_opcode(check *element, instruction_t *opc, positive ln)
{
	int i = 0;
	char *msg = NULL;

	while (opc[i].opcode != NULL)
	{
		if (strcmp(opc[i].opcode, element->opcode) == 0)
		{
			if (strcmp(element->opcode, "push") == 0)
			{
				if (element->arg == NULL || is_number(element->arg) == false)
				{
					msg = _itoa(ln);
					man_er(2, "L", msg, ": usage: push integer");
					free(msg);
					return (2);
				}
				if (atoi(element->arg) == 0 && strcmp(element->arg, "0") != 0
				&& strcmp(element->arg, "-0") != 0)
				{
					msg = _itoa(ln);
					man_er(2, "L", msg, ": usage: push integer");
					free(msg);
					return (2);
				}
			}
			return (1);
		}
		i++;
	}
	return (0);
}
