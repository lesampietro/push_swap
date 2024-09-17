/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:53:42 by lsampiet          #+#    #+#             */
/*   Updated: 2024/09/17 00:06:46 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_diff(t_stack_node *node, t_stack_node **stack_a)
{
	int	i;

	i = 0;
	// ft_printf("min_node -> data: %i, index %i\n", node->data, node->index);
	while(node != *stack_a)
	{
		node = node->prev;
		i++;
	}
	// ft_printf("diff: %i\n", i);
	return (i);
}

t_stack_node	*find_min(t_stack_node **stack_a, int index)
{
	t_stack_node	*tmp;

	tmp = *stack_a;
	while(tmp->index != index)
		tmp = tmp->next;
	return (tmp);
}

void push_min_node(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *min_node)
{
	int	diff;

	diff = find_diff(min_node, stack_a);
	if (diff == 0)
		pb(stack_a, stack_b);
	if (diff == 1 || diff == 2)
	{
		while (min_node != *stack_a)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	if (diff > 2)
	{
		while(min_node != *stack_a)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	sort_five_and_four(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*min_node;
	int				stack_size;

	stack_size = get_stack_size(stack_a);
	min_node = find_min(stack_a, 0);
	if(stack_size == 4)
	{
		push_min_node(stack_a, stack_b, min_node);
		sort_three(stack_a);
		pa(stack_b, stack_a);
	}
	else
	{
		push_min_node(stack_a, stack_b, min_node);
		min_node = find_min(stack_a, 1);
		push_min_node(stack_a, stack_b, min_node);
		sort_three(stack_a);
		pa(stack_b, stack_a);
		pa(stack_b, stack_a);
	}
}
