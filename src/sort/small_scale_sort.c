/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_scale_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:52:51 by kosakats          #+#    #+#             */
/*   Updated: 2025/03/18 15:52:02 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_double(t_node **head_a)
{
	t_node	*first;
	t_node	*second;

	first = *head_a;
	second = first->next;
	if (first->value > second->value)
		sa(head_a);
	return ;
}

void	sort_triple(t_node **head_a)
{
	t_node	*f;
	t_node	*s;
	t_node	*t;

	if (!head_a || !(*head_a) || !(*head_a)->next || !(*head_a)->next->next)
		return ;
	f = *head_a;
	s = f->next;
	t = s->next;
	if (f->value > s->value && s->value < t->value && f->value < t->value)
		sa(head_a);
	else if (f->value > s->value && s->value > t->value)
	{
		sa(head_a);
		rra(head_a);
	}
	else if (f->value > s->value && s->value < t->value && f->value > t->value)
		ra(head_a);
	else if (f->value < s->value && s->value > t->value && f->value < t->value)
	{
		sa(head_a);
		ra(head_a);
	}
	else if (f->value < s->value && s->value > t->value && f->value > t->value)
		rra(head_a);
}

void	sort_six(t_node **stack_a, t_node **stack_b, int size)
{
	int	i;
	int	min_index;

	i = 0;
	while (i < 2)
	{
		min_index = find_min_index(*stack_a);
		move_to_top(stack_a, min_index);
		pb(stack_a, stack_b);
		i++;
	}
	if (size == 6)
		sort_triple(stack_a);
	else
		sort_double(stack_a);
	while (i--)
		pa(stack_a, stack_b);
}
