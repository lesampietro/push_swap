/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:08:16 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/16 16:50:37 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//static functions are only visible inside the file they are declared - for performance optimization purposes
static void	swap(t_stack_node **stack)
{
	int				stack_len;
	
	stack_len = get_stack_size(stack);
	if (!(*stack) || stack_len == 1)
		return ;
	*stack = (*stack)->next; //moving the stack pointer to the second node
	((*stack)->prev)->prev = *stack; //making first node *prev pointer point to new stack position, which points to the second node
	(*stack)->prev->next = (*stack)->next; //making first node *next pointer point to stack's next, which is the third node
	if((*stack)->next) // if there's a third node, we have to manage it's *prev
		(*stack)->next->prev = (*stack)->prev; //third node's *prev was still pointing to the second node. here we make it point to the first node (which is now inbetween the first and the third node)
	(*stack)->next = (*stack)->prev; // making the seconde node's *next point to the first node (the pointer will receive the former *prev pointer value)
	(*stack)->prev = NULL;
	(*stack)->head = *stack;
}

void	sa(t_stack_node **stack_a)
{
	swap(stack_a);
}

void	sb(t_stack_node **stack_b)
{
	swap(stack_b);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}