/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:52:51 by kosakats          #+#    #+#             */
/*   Updated: 2025/03/18 17:41:56 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_list(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	list_size(t_node *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

void	sort_stack(int argc, t_node **stack_a, t_node **stack_b)
{
	if (argc == 2)
		return ;
	if (argc == 3)
		sort_double(stack_a);
	else if (argc == 4)
		sort_triple(stack_a);
	else if (argc >= 5 && argc <= 6)
		sort_six(stack_a, stack_b, argc);
	else
		sort(stack_a, stack_b);
}

void	exit_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		*arr;

	stack_a = NULL;
	stack_b = NULL;
	arr = NULL;
	if (argc < 2)
		return (0);
	handle_arguments(argc, argv, &arr, &stack_a);
	if (!(sort_check(&stack_a)))
	{
		free_list(stack_a);
		free_list(stack_b);
		free(arr);
		return (0);
	}
	sort_stack(argc, &stack_a, &stack_b);
	free_list(stack_a);
	free_list(stack_b);
	free(arr);
	return (0);
}
