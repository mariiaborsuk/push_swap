/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   utils.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: mborsuk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/07 10:39:18 by mborsuk        #+#    #+#                */
/*   Updated: 2025/02/07 10:39:22 by mborsuk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	if_sorted(t_node *a)
{
	t_node	*cur;

	cur = a;
	while (cur)
	{
		if (cur->next && cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

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
	return ((long)sign * result);
}

int	stack_len(t_node *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	send_to_top(t_node **a)
{
	t_node	*smallest;

	smallest = find_smallest(*a);
	if (smallest->above_medium)
	{
		while (*a != smallest)
			ra(a);
	}
	else
	{
		while (*a != smallest)
			rra(a);
	}
}
