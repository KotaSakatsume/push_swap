/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:52:51 by kosakats          #+#    #+#             */
/*   Updated: 2025/03/08 16:37:12 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ss(t_node **head_a, t_node **head_b)
{
	sa(head_a);
	sb(head_b);
	write(1, "ss\n", 3);
}

void	rr(t_node **head_a, t_node **head_b)
{
	ra(head_a);
	rb(head_b);
	write(1, "rr\n", 3);
}

void	rrr(t_node **head_a, t_node **head_b)
{
	rra(head_a);
	rrb(head_b);
	write(1, "rrr\n", 4);
}
