/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_scale_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:52:51 by kosakats          #+#    #+#             */
/*   Updated: 2025/03/18 17:40:44 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bubble(t_node *copy)
{
	t_node	*current;
	t_node	*next;
	int		tmp;

	current = copy;
	while (current)
	{
		next = copy;
		while (next->next)
		{
			if (next->value > next->next->value)
			{
				tmp = next->value;
				next->value = next->next->value;
				next->next->value = tmp;
			}
			next = next->next;
		}
		current = current->next;
	}
}

void	low_element(t_node **stack_a, t_node **stack_b, int size)
{
	int	chunk;
	int	i;
	int	j;

	chunk = size / 5;
	i = 1;
	j = size / 5;
	while (*stack_a)
	{
		if ((*stack_a)->value >= i && (*stack_a)->value <= chunk)
		{
			pb(stack_a, stack_b);
			if ((chunk - ((size / 5) / 2)) >= (*stack_b)->value)
				rb(stack_b);
			if (--j == 0)
			{
				j = size / 5;
				i = chunk + 1;
				chunk += j;
			}
		}
		else
			ra(stack_a);
	}
	sort_insertion(stack_a, stack_b);
}

void	high_element(t_node **stack_a, t_node **stack_b, int size)
{
	int	chunk;
	int	i;
	int	j;

	chunk = size / 10;
	i = 1;
	j = size / 10;
	while (*stack_a)
	{
		if ((*stack_a)->value >= i && (*stack_a)->value <= chunk)
		{
			pb(stack_a, stack_b);
			if ((chunk - ((size / 10) / 2)) >= (*stack_b)->value)
				rb(stack_b);
			if (--j == 0)
			{
				j = size / 10;
				i = chunk + 1;
				chunk += j;
			}
		}
		else
			ra(stack_a);
	}
	sort_insertion(stack_a, stack_b);
}

void	sort_insertion(t_node **stack_a, t_node **stack_b)
{
	int	max;

	while (*stack_b)
	{
		max = find_max(*stack_b);
		if (up_down(*stack_b, max))
		{
			if ((*stack_b)->value == max)
				pa(stack_a, stack_b);
			else
				rb(stack_b);
		}
		else
		{
			if ((*stack_b)->value == max)
				pa(stack_a, stack_b);
			else
				rrb(stack_b);
		}
	}
}

void	sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*copy;
	int		size;

	copy = NULL;
	list_copy(*stack_a, &copy);
	sort_bubble(copy);
	compress(*stack_a, copy);
	free_list(copy);
	size = list_size(*stack_a);
	if (size <= 100)
		low_element(stack_a, stack_b, size);
	else
		high_element(stack_a, stack_b, size);
}
