/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   swap.h                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: mborsuk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/07 10:29:54 by mborsuk        #+#    #+#                */
/*   Updated: 2025/02/07 10:29:59 by mborsuk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_node
{
	int				value;
	int				current_position;
	int				push_price;
	bool			above_medium;
	bool			cheapest;
	struct t_node	*target_node;
	struct t_node	*next;
	struct t_node	*prev;
}					t_node;
int					if_sorted(t_node *a);
long				ft_atoi(const char *str);
t_node				*find_last_node(t_node *head);
int					find_duplicates(t_node *a, int num);
void				add_node(t_node **a, int num);
t_node				*find_smallest(t_node *head);
t_node				*return_cheapest(t_node *stack);
int					stack_len(t_node *stack);
void				stack_init(t_node **a, char **argv);
void				sort_three(t_node **a);
void				set_target_node(t_node *a, t_node *b);
void				set_price(t_node *a, t_node *b);
void				set_cheapest(t_node *b);
void				set_current_position(t_node *stack);
void				init_nodes(t_node *a, t_node *b);
void				reverse_rotate(t_node **stack);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rotate(t_node **stack);
void				ra(t_node **a);
void				rb(t_node **b);
void				swap(t_node **stack);
void				sa(t_node **a);
void				sb(t_node **b);
void				rr(t_node **a, t_node **b);
void				rrr(t_node **a, t_node **b);
void				rotate_both(t_node **a, t_node **b, t_node *cheapest);
void				reverse_rotate_both(t_node **a, t_node **b,
						t_node *cheapest);
void				push(t_node **dest, t_node **src);
void				pa(t_node **a, t_node **b);
void				pb(t_node **b, t_node **a);
void				finish_rotation(t_node **stack, t_node *top,
						char stack_name);
void				move_nodes(t_node **a, t_node **b);
void				push_swap(t_node **a, t_node **b);
char				**ft_split(char const *s, char c);
void				handle_five(t_node **a, t_node **b);
void				send_to_top(t_node **a);
void				*ft_memset(void *str, int c, size_t n);
#endif
