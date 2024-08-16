/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:33:36 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/16 17:49:43 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	int				stack_len;
	t_stack_node	*last_node;

	stack_len = get_stack_size(stack);
	last_node = find_last_node(*stack);
	if (!(*stack) || stack_len == 2)
		return;
	last_node->prev->next = NULL;
	last_node->next = *stack;
	(*stack)->prev = last_node;
	last_node->prev = NULL;
	*stack = last_node;
	(*stack)->head = last_node;
}

void	rra(t_stack_node **stack_a)
{
	rev_rotate(stack_a);
}

void	rrb(t_stack_node **stack_b)
{
	rev_rotate(stack_b);
}

void rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}