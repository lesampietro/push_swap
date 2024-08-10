/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:32:44 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/10 19:27:10 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack_node **src_stack, t_stack_node **dest_stack)
{
	t_stack_node	*node_to_push;
	
	node_to_push = *src_stack;
	*src_stack = (*src_stack)->next; // make it point to the next node
	if(*src_stack) // make its prev pointer point to NULL turning it head node
		(*src_stack)->prev = NULL;
	if(*dest_stack == NULL) // if the destination stack is empty
	{
		*dest_stack = node_to_push; // make the destination stack point to the node_to_push
		node_to_push->prev = NULL; // make the node_to_push same as head node
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest_stack; // make the node_to_push next pointer point to the destination stack
		node_to_push->next->prev = node_to_push;
		*dest_stack = node_to_push; //
	}

}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_b, stack_a);
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
}