/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mborsuk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/07 10:23:45 by mborsuk        #+#    #+#                */
/*   Updated: 2025/02/07 10:23:49 by mborsuk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

// void	print_list(t_node *a)
// {
// 	while (a)
// 	{
// 		printf("%d -> ", a->value);
// 		a = a->next;
// 	}
// 	printf("NULL\n");
// }

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->next = NULL;
		current->prev = NULL;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	free_numbers(char **num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		free(num[i]);
		i++;
	}
	free(num);
}

void	check_len(t_node **a, t_node **b)
{
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		push_swap(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**numbers;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers)
			return (1);
		if (*numbers == NULL)
			return (free(numbers), write(2, "Error\n", 6), 1);
		stack_init(&a, numbers);
		free_numbers(numbers);
	}
	else
		stack_init(&a, argv + 1);
	if (!if_sorted(a))
		check_len(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
