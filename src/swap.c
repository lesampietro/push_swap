/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:08:16 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/10 17:53:50 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static void	swap(t_stack_node **stack) //swaping node's values
// {
// 	int				tmp_value;
// 	t_stack_node	*tmp_node;

// 	if (!(*stack) || !(*stack)->next)
// 		return ;
// 	tmp_value = (*stack)->data;
// 	(*stack)->data = (*stack)->next->data;
// 	(*stack)->next->data = tmp_value;
// 	tmp_node = *stack;
// 	while (tmp_node != NULL)
// 	{
// 		ft_printf("tmp_node->data: %d\n", tmp_node->data);
// 		tmp_node = tmp_node->next;
// 	}
// }

static void	swap(t_stack_node **stack) //swaping node's positions
{
	t_stack_node	*head_node;

	if (!(*stack) || !(*stack)->next)
		return ;
	head_node = *stack;
	*stack = (*stack)->next;
	// while (tmp_node != NULL)
	// {
	// 	ft_printf("tmp_node->data: %d\n", tmp_node->data);
	// 	tmp_node = tmp_node->next;
	// }
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