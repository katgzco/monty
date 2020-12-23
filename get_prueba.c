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
		exit(1);
	}

/*open file*/
	file_manage(argv[1]);

	return (0);
}

/**
 * divide_file - frees a list
 * @check_file: the file open.
 * @array: struct array to store file inf.
 * @head: the head if the link list.
 * @opc: struct.
 * Return: 0 in succes -1 in error.
*/

int divide_file(FILE *check_file, check *array, stack_t **head,
instruction_t *opc)
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
			if (opc_f(idx, false, array, head, ln, opc) == -1)
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
	ret = opc_f(0, true, array, head, ln, opc);
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
	instruction_t opc[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"nop", nop}, {"add", add}, {"swap", swap},
		{"sub", sub}, {"div", _div},
		{NULL, NULL}};

	check_file = fopen(file_name, "r");
	/*check succes or not of the open file*/
	if (check_file == NULL)
	{
		man_er(1, "Error: Can't open file ", file_name);
		exit(1);
	}
	/*read line per line of the  file*/
	ret = divide_file(check_file, array, &head, opc);
	if (ret == -1 || ret == 0)
		free_opc(array, &head, check_file);

	if  (ret == -1)
		exit(1);
}
