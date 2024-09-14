/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:53:42 by lsampiet          #+#    #+#             */
/*   Updated: 2024/09/11 17:12:34 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/push_swap.h"

// int	find_diff(t_stack_node *node, t_stack_node **stack_a)
// {
// 	t_stack_node *tmp;
// 	int	i = 0;

// 	tmp = node;
// 	while(tmp != *stack_a)
// 	{
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	return (i);
// }

// t_stack_node	*find_min(t_stack_node **stack_a, int index)
// {
// 	t_stack_node	*tmp;

// 	tmp = *stack_a;
// 	while(tmp->index != index)
// 		tmp = tmp->next;
// 	return (tmp);
// }

// void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
// {
// 	t_stack_node	*min_00;
	// t_stack_node	*min_01;
	// int				diff;

	// min_00 = find_min(stack_a, 0);
	// diff = find_diff(min_00, stack_a);
	// if(diff == 1)
	// 	ra(stack_a);
	// if (diff == 2)
	// {
	// 	ra(stack_a);
	// 	ra(stack_a);
	// }
	// if (diff == 3)
	// {
	// 	rra(stack_a);
	// 	rra(stack_a);
	// }
	// if (diff == 4)
	// 	rra(stack_a);
	// pb(stack_a, stack_b);
	// min_01 = find_min(stack_a, 1);
	// max_node = find_max(stack_a, ((*stack_a)->size) - 1);
// 	sort_three(stack_a);
// 	pa(stack_b, stack_a);
// }

// t_stack_node	*find_max(t_stack_node **stack_a, int max_index)
// {
// 	t_stack_node	*tmp;

// 	tmp = *stack_a;
// 	while(tmp->index != max_index)
// 		tmp = tmp->next;
// 	return (tmp);
// }