/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_4.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mborsuk <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 10:33:11 by mborsuk       #+#    #+#                 */
/*   Updated: 2025/02/08 15:07:25 by mborsuk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

size_t	ft_strlen(const char *str)
{
	const char	*orig;

	orig = str;
	while (*str)
		str++;
	return (str - orig);
}

void	handle_five(t_node **a, t_node **b)
{
	send_to_top(a);
	pb(b, a);
	send_to_top(a);
	pb(b, a);
}

int	is_number(const char *str)
{
	if (!str || !*str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	stack_init(t_node **a, char **argv)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11 || !is_number(argv[i]))
		{
			write(1, "Error\n", 6);
			exit(2);
		}
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN || find_duplicates(*a, (int)num))
		{
			write(1, "Error\n", 6);
			exit(2);
		}
		add_node(a, (int)num);
		i++;
	}
}

void	sort_three(t_node **a)
{
	while (!if_sorted(*a))
	{
		if (*a && (*a)->next && (*a)->value > (*a)->next->value)
		{
			sa(a);
		}
		else
		{
			rra(a);
		}
	}
}
