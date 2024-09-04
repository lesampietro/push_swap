/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:28:47 by lsampiet          #+#    #+#             */
/*   Updated: 2024/09/04 19:29:25 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// checa se há um número menor em algum dos nós da lista, com um endereço de target passado a partir da função de chamada
t_stack_node	*find_smallest(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*target;

	tmp = *stack;
	target = NULL;
	while (tmp != NULL)
	{
		if ((target == NULL || target->data > tmp->data) && tmp->index == -1)
			target = tmp;
		tmp = tmp->next;
	}
	return (target);
}

void	set_index(t_stack_node **stack)
{
	t_stack_node	*min_node;
	int	i;

	i = 0;
	while (i < (*stack)->size)
	{
		min_node = find_smallest(stack);
		min_node->index = i;
		i++;
	}
}