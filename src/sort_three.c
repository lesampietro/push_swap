/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:14:08 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/18 20:45:34 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack_node **stack)
{
	int	first;
	int second;
	int third;

	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->next->next->data;
	if(first < second && second < third)
		return;
	if(first < second && second > third)
	{
		sa(stack);
		ra(stack);
	}
	if(first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	if (first > second && second < third)
		sa(stack);
	return;
}