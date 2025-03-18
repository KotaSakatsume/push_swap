/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_scale_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:52:51 by kosakats          #+#    #+#             */
/*   Updated: 2025/03/18 17:05:05 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	up_down(t_node *stack_b, int max)
{
	while (stack_b)
	{
		if (stack_b->value == max)
			return (1);
		else if (stack_b->value == 1)
			return (0);
		stack_b = stack_b->next;
	}
	return (0);
}

int	find_max(t_node *stack_b)
{
	int	max;

	if (!stack_b)
		return (INT_MIN);
	max = stack_b->value;
	while (stack_b)
	{
		if (stack_b->value > max)
			max = stack_b->value;
		stack_b = stack_b->next;
	}
	return (max);
}

void	compress(t_node *stack_a, t_node *copy)
{
	t_node	*tmp;
	int		i;

	i = 1;
	while (stack_a)
	{
		tmp = copy;
		i = 1;
		while (tmp)
		{
			if (stack_a->value == tmp->value)
			{
				stack_a->value = i;
				break ;
			}
			i++;
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
}

void	list_copy(t_node *src, t_node **dest)
{
	t_node	*new_node;
	t_node	*current;

	*dest = NULL;
	while (src)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->value = src->value;
		new_node->next = NULL;
		if (*dest == NULL)
		{
			*dest = new_node;
			current = *dest;
		}
		else
		{
			current->next = new_node;
			current = current->next;
		}
		src = src->next;
	}
}
