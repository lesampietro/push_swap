/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:32:52 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/18 17:52:18 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	int				stack_len;
	t_stack_node	*last_node;

	stack_len = get_stack_size(stack);
	last_node = find_last_node(*stack);
	if (!(*stack) || !(*stack)->next || stack_len == 2)
		return;
	*stack = (*stack)->next;
	(*stack)->prev->prev = last_node;
	last_node->next = (*stack)->prev;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	(*stack)->head = *stack;
}

void	ra(t_stack_node **stack_a)
{
	rotate(stack_a);
}

void	rb(t_stack_node **stack_b)
{
	rotate(stack_b);
}

void rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!(*stack_a) || !(*stack_b))
		return;
	rotate(stack_a);
	rotate(stack_b);
}