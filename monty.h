#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

extern char *nodo_ini;
typedef unsigned int positive;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct check - file information
 * @arg: argument of the opcode
 * @opcode: the opcode
 *
 * Description: struct of filename and 1 arg.
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct check
{
	char *arg;
	char *opcode;
} check;

void file_manage(char *file_name);
void man_er(int size, const char *mesge, ...);
char *copy_string(char *dest);
int divide_file(FILE *, check *, stack_t **, instruction_t *);
int check_opcode(check *element, instruction_t *opc, positive ln);
int count_digits(int number);
char *_itoa(int number);
int opc_f(int, bool, check *, stack_t **, positive, instruction_t *);
void pint(stack_t **stack, unsigned int ln);
void free_opc(check *array, stack_t **s, FILE *check_file);
void free_arr(check *array);
void free_dlistint(stack_t *head);
char *copy_string(char *dest);
bool is_number(char *str);

/*function for search*/
void push(stack_t **stack, unsigned int ln);
void pall(stack_t **stack, unsigned int ln);
void nop(stack_t **stack, unsigned int ln);
void pop(stack_t **stack, unsigned int ln);
void add(stack_t **stack, unsigned int ln);
void swap(stack_t **stack, unsigned int ln);
void sub(stack_t **stack, unsigned int ln);
void mod(stack_t **stack, unsigned int ln);
void mul(stack_t **stack, unsigned int ln);
void _div(stack_t **stack, unsigned int ln);
instruction_t *struc_op(void);
#endif


