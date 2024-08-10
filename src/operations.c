/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:23:06 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/09 19:41:53 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*insert_at_head(t_stack_node *stack, int data)
{
	t_stack_node	*new_node;

	new_node = create_node(data);
	if (stack->head == NULL)
		stack->head = new_node;
	else
	{
		new_node->next = stack;
		stack->head = new_node;
		stack->prev = new_node;
		stack = new_node;
	}
	return (stack);
}

t_stack_node	*sa(t_stack_node **stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return (stack);
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
	return (stack);
}

int	pop(t_stack_node *node)
{
	int tmp;

	if (!node || !node->next)
		return (1);
	tmp = node->data;
	node->head = node->next;
	// free(node);
	return (tmp);
}

void	push(t_stack_node *stack, int tmp)
{
	t_stack_node	*temp; //criar um nó temporário para conseguir manipular a lista sem perder referências
	
	*stack_b = NULL;
	node_b->next = node_a;
	node_a->prev = node_b;	
}

