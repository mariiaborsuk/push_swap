/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rotate.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: mborsuk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/07 10:27:14 by mborsuk        #+#    #+#                */
/*   Updated: 2025/02/07 10:27:20 by mborsuk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	rotate(t_node **stack)
{
	t_node	*last;

	if (stack == NULL || *stack == NULL)
		return ;
	last = find_last_node(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
	{
		rr(a, b);
	}
	set_current_position(*a);
	set_current_position(*b);
}
