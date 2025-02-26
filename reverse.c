/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   reverse.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: mborsuk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/07 10:26:01 by mborsuk        #+#    #+#                */
/*   Updated: 2025/02/07 10:26:04 by mborsuk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	reverse_rotate(t_node **stack)
{
	t_node	*last;

	if (stack == NULL || *stack == NULL)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

void	reverse_rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
	{
		rrr(a, b);
	}
	set_current_position(*a);
	set_current_position(*b);
}
