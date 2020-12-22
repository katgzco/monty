#include "monty.h"

char *nodo_ini = NULL;
/**
 * main - function that get the terminal arg.
 * @argc: the numbero of arguments.
 * @argv: array of arguments
 * Return: 0 in succes.
*/
int main(int argc, char *argv[])
{
/*check existing file*/
	if (argc !=  2)
	{
		man_er(0, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

/*open file*/
	file_manage(argv[1]);

	return (0);
}

/**
 * divide_file - frees a list
 * @check_file: the file open.
 * @array: struct array to store file inf.
 * @head: the head if the link list..
 * Return: 0 in succes -1 in error.
*/

int divide_file(FILE *check_file, check *array, stack_t **head)
{
	char *token = NULL, *line = NULL;
	size_t size = 0;
	positive control = 0, ln = 0, idx = 0;
	ssize_t check_get = 0;
	const char *delim = " \n";
	int ret = 0;

	while ((check_get = getline(&line, &size, check_file)) != -1)
	{
		control = 0, ln++;
		array[idx].opcode = NULL;
		array[idx].arg = NULL;
		token = strtok(line, delim);
		while (token)
		{
			control++;
			if (control >= 2)
				break;
			array[idx].opcode = copy_string(token);
			token = strtok(NULL, delim);
			array[idx].arg = copy_string(token);
			array[idx + 1].opcode = NULL;
			array[idx + 1].arg = NULL;
		}
		if (array[idx].opcode != NULL)
		{
			if (opc_f(idx, false, array, head, ln) == -1)
			{
				free(line);
				return (-1);
			}
			idx++;
		}
	}
	array[idx].opcode = NULL;
	array[idx].arg = NULL;
	free(line);
	ret = opc_f(0, true, array, head, ln);
	return (ret);
}

/**
 * file_manage - manages the input file
 * @file_name: name of the file.
 * Return: void.
*/
void file_manage(char *file_name)
{
	FILE *check_file = NULL;
	check array[BUFSIZ];
	int ret = 0;
	stack_t *head = NULL;

	check_file = fopen(file_name, "r");
	/*check succes or not of the open file*/
	if (check_file == NULL)
	{
		man_er(1, "Can't open file ", file_name);
		exit(EXIT_FAILURE);
	}
	/*read line per line of the  file*/
	ret = divide_file(check_file, array, &head);
	if (ret == -1 || ret == 0)
		free_opc(array, &head, check_file);

	if  (ret == -1)
		exit(EXIT_FAILURE);
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
				if (element->arg == NULL)
				{
					msg = _itoa(ln);
					man_er(2, "L", msg, ": usage: push integer");
					free(msg);
						return (2);
				}
				if (atoi(element->arg) == 0 && strcmp(element->arg, "0") != 0)
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
/**
 * opc_f - check the match for the function and control it .
 * @idx: the index of the array.
 * @exec: contro the error or execution.
 * @array: struct array to store file inf.
 * @s: the head of the link list.
 * @ln: the num of lines.
 * Return: the new string.
*/
int opc_f(int idx, bool exec, check *array, stack_t **s, positive ln)
{
	int i = 0, j = 0, ret = 0;
	char *msg = NULL;
	instruction_t opc[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{NULL, NULL}};

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
					opc[j].f(s, ln);
					if (nodo_ini != NULL && strcmp(nodo_ini, "Error") == 0)
						return (-1);
					break;
				} j++;
			} i++;
		}
	}
	return (0);
}
