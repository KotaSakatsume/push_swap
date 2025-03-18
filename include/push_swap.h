/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:52:51 by kosakats          #+#    #+#             */
/*   Updated: 2025/03/18 18:31:58 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

void				sa(t_node **head);
void				sb(t_node **head);
void				ss(t_node **head_a, t_node **head_b);
void				pa(t_node **head_a, t_node **head_b);
void				pb(t_node **head_a, t_node **head_b);
void				ra(t_node **head);
void				rb(t_node **head);
void				rr(t_node **head_a, t_node **head_b);
void				rra(t_node **head);
void				rrb(t_node **head);
void				rrr(t_node **head_a, t_node **head_b);
t_node				*create_node(int value);
void				append_node(t_node **head, int value);
void				handle_arguments(int argc, char **argv, int **arr,
						t_node **stack_a);
void				print_stack(const char *name, t_node *head);
void				sort_double(t_node **head_a);
void				sort_triple(t_node **head_a);
void				sort_six(t_node **stack_a, t_node **stack_b, int size);
int					list_size(t_node *stack_a);
void				list_copy(t_node *src, t_node **dest);
int					find_max(t_node *stack_b);
int					find_min(t_node *stack_a);
void				free_list(t_node *head);
int					up_down(t_node *stack_b, int max);
void				compress(t_node *stack_a, t_node *copy);
int					is_int(const char *str);
int					duplication_check(int *arr, int size);
void				exit_error(void);
void				move_to_top(t_node **stack, int target_index);
int					find_min_index(t_node *stack);
int					get_stack_size(t_node *stack);
void				handle_error(int **arr, t_node **stack_a);
void				handle_arguments(int argc, char **argv, int **arr,
						t_node **stack_a);
void				sort_bubble(t_node *copy);
void				sort_insertion(t_node **stack_a, t_node **stack_b);
void				sort(t_node **stack_a, t_node **stack_b);
int					sort_check(t_node **stack_a);
#endif