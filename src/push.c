/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:32:44 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/18 17:34:03 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack_node **src_stack, t_stack_node **dest_stack)
{
	t_stack_node	*node_to_push;

	if (!(*src_stack) || !(*src_stack)->next)
		return ;
	node_to_push = *src_stack;
	*src_stack = (*src_stack)->next;
	(*src_stack)->prev = NULL;
	if(!(*dest_stack))
	{
		*dest_stack = node_to_push;
		node_to_push->prev = NULL;
		node_to_push->next = NULL;
	}
	else
	{
		( *dest_stack)->prev = node_to_push;
		node_to_push->next = *dest_stack;
		*dest_stack = node_to_push;
	}
	(*src_stack)->head = *src_stack;
	(*dest_stack)->head = *dest_stack;
}

void	pa(t_stack_node **stack_b, t_stack_node **stack_a)
{
	push(stack_b, stack_a);
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
}