/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   utils_3.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: mborsuk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/07 10:32:20 by mborsuk        #+#    #+#                */
/*   Updated: 2025/02/07 10:32:23 by mborsuk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	set_target_node(t_node *a, t_node *b)
{
	t_node	*cur_a;
	t_node	*target_node;
	int		best_match_index;

	while (b)
	{
		best_match_index = INT_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->value > b->value && cur_a->value < best_match_index)
			{
				best_match_index = cur_a->value;
				target_node = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best_match_index == INT_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_medium))
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_medium)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_node *b)
{
	int		best_match_val;
	t_node	*best_match_node;

	if (b == NULL)
		return ;
	best_match_val = INT_MAX;
	while (b)
	{
		if (b->push_price < best_match_val)
		{
			best_match_val = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	set_current_position(t_node *stack)
{
	int	i;
	int	medium;

	i = 0;
	if (stack == NULL)
		return ;
	medium = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= medium)
			stack->above_medium = true;
		else
			stack->above_medium = false;
		stack = stack->next;
		i++;
	}
}

void	init_nodes(t_node *a, t_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
