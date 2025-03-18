/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:52:51 by kosakats          #+#    #+#             */
/*   Updated: 2025/03/08 16:32:57 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!head || !(*head) || !(*head)->next)
		return ;
	first = *head;
	*head = first->next;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!head || !(*head) || !(*head)->next)
		return ;
	first = *head;
	*head = first->next;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rra(t_node **head)
{
	t_node	*prev;
	t_node	*last;

	if (!head || !(*head) || !(*head)->next)
		return ;
	last = *head;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *head;
	*head = last;
	prev->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_node **head)
{
	t_node	*prev;
	t_node	*last;

	if (!head || !(*head) || !(*head)->next)
		return ;
	last = *head;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *head;
	*head = last;
	prev->next = NULL;
	write(1, "rrb\n", 4);
}
