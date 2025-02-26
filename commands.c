/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   commands.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: mborsuk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/07 10:20:38 by mborsuk        #+#    #+#                */
/*   Updated: 2025/02/07 10:20:53 by mborsuk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	swap(t_node **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	finish_rotation(t_node **stack, t_node *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_medium)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top->above_medium)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_nodes(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->above_medium && cheapest->target_node->above_medium)
		rotate_both(a, b, cheapest);
	else if (!cheapest->above_medium && !cheapest->target_node->above_medium)
		reverse_rotate_both(a, b, cheapest);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target_node, 'a');
	pa(a, b);
}
