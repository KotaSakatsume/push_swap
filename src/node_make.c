/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_make.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:52:51 by kosakats          #+#    #+#             */
/*   Updated: 2025/03/18 17:54:19 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(int **arr, t_node **stack_a)
{
	free(*arr);
	free_list(*stack_a);
	exit_error();
}

void	handle_arguments(int argc, char **argv, int **arr, t_node **stack_a)
{
	int	i;
	int	num;

	*arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!*arr)
		return ;
	i = 0;
	while (++i < argc)
	{
		if (!is_int(argv[i]))
			handle_error(arr, stack_a);
		num = ft_atoi(argv[i]);
		(*arr)[i - 1] = num;
		append_node(stack_a, num);
	}
	if (!duplication_check(*arr, argc - 1))
		handle_error(arr, stack_a);
}

void	append_node(t_node **head, int value)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = create_node(value);
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (new_node);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}
