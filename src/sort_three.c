/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:14:08 by lsampiet          #+#    #+#             */
/*   Updated: 2024/09/16 23:59:54 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_first(t_stack_node **stack_a)
{
	int	first;
	int	second;
	int	third;
	int	level;

	level = 0;
	first = (*stack_a)->data;
	second = ((*stack_a)->next)->data;
	third = (*stack_a)->next->next->data;
	if (first < second && first < third && second > third) // 1 3 2
		level = TOP;
	if (first < second && first > third) // 2 3 1
		level = MIDDLE_01;
	if (first > second && first < third) // 2 1 3
		level = MIDDLE_02;
	if (first > second && first > third && second > third) // 3 2 1
		level = BOTTOM_01;
	if (first > second && first > third && second < third) // 3 1 2
		level = BOTTOM_02;
	return (level);
}

void	sort_three(t_stack_node **stack_a)
{
	int	level;

	level = sort_first(stack_a);
	if (is_sorted(stack_a))
		return;
	if (level == TOP)
	{
		rra(stack_a);
		sa(stack_a);
	}
	if (level == MIDDLE_01)
		rra(stack_a);
	if (level == MIDDLE_02)
		sa(stack_a);
	if (level == BOTTOM_01)
	{
		ra(stack_a);
		sa(stack_a);
	}
	if (level == BOTTOM_02)
		ra(stack_a);
	return ;
}
