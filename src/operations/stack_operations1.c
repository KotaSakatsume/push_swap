/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:52:51 by kosakats          #+#    #+#             */
/*   Updated: 2025/03/08 16:32:39 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_node **head)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!head || !(*head) || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write(1, "sa\n", 3);
}

void	sb(t_node **head)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!head || !(*head) || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write(1, "sb\n", 3);
}

void	pa(t_node **head_a, t_node **head_b)
{
	t_node	*temp;

	if (!head_b || !(*head_b))
		return ;
	temp = *head_b;
	*head_b = temp->next;
	temp->next = *head_a;
	*head_a = temp;
	write(1, "pa\n", 3);
}

void	pb(t_node **head_a, t_node **head_b)
{
	t_node	*temp;

	if (!head_a || !(*head_a))
		return ;
	temp = *head_a;
	*head_a = temp->next;
	temp->next = *head_b;
	*head_b = temp;
	write(1, "pb\n", 3);
}
