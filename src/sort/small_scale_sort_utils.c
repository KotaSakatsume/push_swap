/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_scale_sort_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:52:51 by kosakats          #+#    #+#             */
/*   Updated: 2025/03/18 15:45:37 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_node *stack_a)
{
	int	min;

	min = 0;
	min = stack_a->value;
	while (stack_a)
	{
		if (stack_a->value < min)
			min = stack_a->value;
		stack_a = stack_a->next;
	}
	return (min);
}

int	get_stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	find_min_index(t_node *stack)
{
	int	min_value;
	int	min_index;
	int	index;

	min_value = stack->value;
	min_index = 0;
	index = 0;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (min_index);
}

void	move_to_top(t_node **stack, int target_index)
{
	int	stack_size;

	stack_size = get_stack_size(*stack);
	if (target_index <= stack_size / 2)
	{
		while (target_index--)
			ra(stack);
	}
	else
	{
		target_index = stack_size - target_index;
		while (target_index--)
			rra(stack);
	}
}
