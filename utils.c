#include "swap.h"
int if_sorted(t_stack *a)
{
	t_node *cur=a->top;
	while(cur)
	{
		if(cur->next && cur->value > cur->next->value)
			return 0;
		cur=cur->next;
	}
	return 1;

}
bool	sa(t_program *program)
{
	t_node	*first;
	t_node	*second;

	if (!program || !program->a || program->a->size < 2)
		return (false);
	first = program->a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	program->a->top = second;
	write(1,"sa\n",4);
	program->operation_count++;
	return (true);
}

bool	pb(t_program *program)
{
	int	value;

	if (!program || !program->a || !program->b || program->a->size == 0)
		return (false);
	if (!pop(program->a, &value))
		return (false);
	if (!push(program->b, value))
	{
		push(program->a, value);
		return (false);
	}
	write(1, "pb\n",4);
	program->operation_count++;
	return (true);
}

bool	pa(t_program *program)
{
	int	value;

	if (!program || !program->a || !program->b || program->b->size == 0)
		return (false);
	if (!pop(program->b, &value))
		return (false);
	if (!push(program->a, value))
	{
		push(program->b, value);
		return (false);
	}
	write(1,"pa\n",4);
	program->operation_count++;
	return (true);
}

void ra(t_program *program)
{
	t_node	*first;
	t_node	*last;

	first = program->a->top;
	program->a->top = first->next;
	last = program->a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1,"ra\n",4);
	program->operation_count++;

}

bool	push(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		return (false);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (false);
	new_node->value = value;
	new_node->next = stack->top;
	new_node->index = -1;
	stack->top = new_node;
	stack->size++;
	return (true);
}
void	stack_init(t_stack *stack)
{
	if (!stack)
		return ;
	stack->top = NULL;
	stack->size = 0;
}
int ft_is_digit(char c)
{
    return (c >= '0' && c <= '9');
}
long	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (!ft_is_digit(str[i]))
		return (0);
	while (ft_is_digit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	long res= (long)sign *(long) result;
	return res;
}

// t_sign return_sign(const char *str)
// {
//     t_sign sign_and_index;
//     int i;

//     i = 0;
//     while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
//         i++;
//     sign_and_index.sign = 1;
//     if (str[i] == '+' || str[i] == '-')
//     {
//         if (str[i] == '-')
//             sign_and_index.sign = -1;
//         i++;
//     }
//     sign_and_index.i = i;
//     return sign_and_index;
// }

// int ft_atoi(const char *str, int *num)
// {
//     long result;
//     t_sign index_and_sign;

//     if (!str || !num)
//         return (0);
//     result = 0;
//     index_and_sign = return_sign(str);
//     if (!ft_is_digit(str[index_and_sign.i]))
//         return (0);
//     while (ft_is_digit(str[index_and_sign.i]))
//     {
//         if (result > (INT_MAX - (str[index_and_sign.i] - '0')) / 10)
//             return (0);
//         result = result * 10 + (str[index_and_sign.i] - '0');
//         index_and_sign.i++;
//     }
//     if (str[index_and_sign.i] != '\0')
//         return (0);
//     if ((index_and_sign.sign == 1 && result > INT_MAX) ||
//         (index_and_sign.sign == -1 && result > (long)INT_MAX + 1))
//         return (0);
//     *num = (int)(index_and_sign.sign * result);
//     return (1);
// }
// int	ft_is_digit(char c)
// {
// 	return (c >= '0' && c <= '9');
// }

// int    ft_atoi(const char *str, int *num)
// {
//     long    result;
// 	t_sign	index_and_sign;

// 	if (!str)
// 		return (0);
// 	result = 0;
// 	index_and_sign=return_sign(str);
//     if (!ft_is_digit(str[index_and_sign.i]))
//         return (0);
//     while (ft_is_digit(str[index_and_sign.i]) && result <= INT_MAX)
//     {
//         result = result * 10 + (str[index_and_sign.i] - '0');
//         index_and_sign.i++;
//     }
//     if (str[index_and_sign.i] != '\0')
//         return (0);
//     if (result > INT_MAX)
//         return (0);
//     *num = (int)(index_and_sign.sign * result);
//     return (1);
// }
// t_sign	return_sign(const char *str)
// {
// 	t_sign sign_and_index;
// 	int        i;
// 	int        sign;

// 	i = 0;
//     sign = 1;
//     while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
//         i++;
//     if (str[i] == '+' && str[i + 1] != '-')
//         i++;
//     if (str[i] == '-')
//     {
//         sign = -1;
//         i++;
//     }
// 	sign_and_index.i=i;
// 	sign_and_index.sign=sign;
// 	return sign_and_index;
// }
// t_sign	return_sign(const char *str)
// {
//     t_sign sign_and_index;
//     int    i;
//     int    sign;

//     if (!str)  // Add this check
//     {
//         sign_and_index.i = 0;
//         sign_and_index.sign = 1;
//         return sign_and_index;
//     }

//     i = 0;
//     sign = 1;
//     while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
//         i++;
//     if (str[i] == '+' && str[i + 1] != '-')
//         i++;
//     if (str[i] == '-')
//     {
//         sign = -1;
//         i++;
//     }
//     sign_and_index.i = i;
//     sign_and_index.sign = sign;
//     return sign_and_index;
// }

// int    ft_atoi(const char *str, int *num)
// {
//     long    result;
//     t_sign  index_and_sign;

//     if (!str || !num)  // Also check num pointer
//         return (0);
//     result = 0;
//     index_and_sign = return_sign(str);
//     if (!ft_is_digit(str[index_and_sign.i]))
//         return (0);
//     while (ft_is_digit(str[index_and_sign.i]) && result <= INT_MAX)
//     {
//         result = result * 10 + (str[index_and_sign.i] - '0');
//         index_and_sign.i++;
//     }
//     if (str[index_and_sign.i] != '\0')
//         return (0);
//     if (result > INT_MAX)
//         return (0);
//     *num = (int)(index_and_sign.sign * result);
//     return (1);
// }
void	program_init(t_program *program, t_stack *a, t_stack *b)
{
	if (!program)
		return ;
	program->a = a;
	program->b = b;
	program->operation_count = 0;
	program->sorted_array = NULL;
	program->chunk_size = 0;
	program->total_size = 0;
}

bool	pop(t_stack *stack, int *value)
{
	t_node	*temp;

	if (!stack || !stack->top || !value)
		return (false);
	temp = stack->top;
	*value = temp->value;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (true);
}
void bubble_sort(t_program *program)
{
	int i;
	int j;
	int		temp;

	i=0;
	while (i < program->total_size - 1)
	{
		j=0;
		while ( j < program->total_size - i - 1)
		{
			if (program->sorted_array[j] > program->sorted_array[j + 1])
			{
				temp = program->sorted_array[j];
				program->sorted_array[j] = program->sorted_array[j + 1];
				program->sorted_array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
void	rra(t_program *program)
{
	t_node	*current;
	t_node	*prev;

	current = program->a->top;
	prev = NULL;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = program->a->top;
	program->a->top = current;
	write(1,"rra\n",5);
	program->operation_count++;

}
