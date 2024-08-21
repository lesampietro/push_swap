/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:32:44 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/21 18:30:05 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	manage_src(t_stack_node **src_stack)
{
	int stack_len;

	stack_len = get_stack_size(src_stack);
	if (stack_len == 1)
		*src_stack = NULL;
	if (stack_len > 1)
	{
		*src_stack = (*src_stack)->next;
		(*src_stack)->prev = NULL;
		(*src_stack)->head = *src_stack;
	}
	return;
}

static void	push(t_stack_node **src_stack, t_stack_node **dest_stack)
{
	t_stack_node	*node_to_push;

	if (!(*src_stack))
		return;
	node_to_push = *src_stack;
	manage_src(src_stack);
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
	(*dest_stack)->head = *dest_stack;
}

void	pa(t_stack_node **src_stack, t_stack_node **dest_stack)
{
	push(src_stack, dest_stack);
}

void	pb(t_stack_node **src_stack, t_stack_node **dest_stack)
{
	push(src_stack, dest_stack);
}