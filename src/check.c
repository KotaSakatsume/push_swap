/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:52:51 by kosakats          #+#    #+#             */
/*   Updated: 2025/03/18 17:41:28 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplication_check(int *arr, int size)
{
	int	i;
	int	j;

	if (arr == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_int(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	sort_check(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	first = *stack_a;
	second = first->next;
	while (first && second)
	{
		if (first->value > second->value)
			return (1);
		first = first->next;
		second = second->next;
	}
	return (0);
}
