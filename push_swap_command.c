/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap_command.c                                 :+:    :+:           */
/*                                                      +:+                   */
/*   By: mborsuk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/07 10:22:25 by mborsuk        #+#    #+#                */
/*   Updated: 2025/02/07 10:22:29 by mborsuk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	push_swap(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
	{
		handle_five(a, b);
	}
	else
	{
		while (len_a-- > 3)
			pb(b, a);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	send_to_top(a);
}
