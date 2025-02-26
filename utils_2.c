/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   utils_2.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: mborsuk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/07 10:31:03 by mborsuk        #+#    #+#                */
/*   Updated: 2025/02/07 10:31:07 by mborsuk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

t_node	*find_last_node(t_node *head)
{
	if (head == NULL)
	{
		return (NULL);
	}
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}

int	find_duplicates(t_node *a, int num)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}

void	add_node(t_node **a, int num)
{
	t_node	*node;
	t_node	*last_node;

	if (a == NULL)
		return ;
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = num;
	node->above_medium = false;
	if (*a == NULL)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_node	*find_smallest(t_node *head)
{
	long	smallest;
	t_node	*smallest_node;

	if (head == NULL)
	{
		return (NULL);
	}
	smallest = LONG_MAX;
	while (head)
	{
		if (head->value < smallest)
		{
			smallest = head->value;
			smallest_node = head;
		}
		head = head->next;
	}
	return (smallest_node);
}

t_node	*return_cheapest(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
