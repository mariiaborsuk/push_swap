#ifndef SWAP_H
#define SWAP_H
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int index;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

typedef struct s_program
{
	t_stack			*a;
	t_stack			*b;
	int				operation_count;
	int				*sorted_array;
	int				chunk_size;
	int				total_size;
}					t_program;
typedef struct t_sign
{
	int sign;
	int i;
}				t_sign;
bool	pop(t_stack *stack, int *value);
int if_sorted(t_stack *a);
bool	sa(t_program *program);
bool	pb(t_program *program);
bool	pa(t_program *program);
void	ra(t_program *program);
bool	push(t_stack *stack, int value);
void	stack_init(t_stack *stack);
int	ft_is_digit(char c);
long    ft_atoi(const char *str);
void	program_init(t_program *program, t_stack *a, t_stack *b);
t_sign	return_sign(const char *str);
void bubble_sort(t_program *program);
void	rra(t_program *program);

#endif
