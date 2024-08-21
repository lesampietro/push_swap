/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:14:08 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/21 17:41:36 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//DIVIDIR A FUNÇAO PRA ANALISAR PRIMEIRO SÓ O PRIMEIRO NÓ EM COMP COM OS OUTROS DOIS. DEPOIS COMP OS DOIS SEPARADO E ORDENA
int	sort_first(int first, int second, int third)
{
	int	level;
	
	if (first < second && first < third)
		level = TOP;
	if (first < second && first > third)
		level = MIDDLE;
	if (first > second && first < third)
		level = MIDDLE;
	if (first > second && first > third)
		level = BOTTOM;
	return (level);
}

void	sort_three(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	first;
	int	second;
	int	third;
	int	level;

	first = (*stack_a)->data;
	second = ((*stack_a)->next)->data;
	third = (*stack_a)->next->next->data;
	level = sort_first(first, second, third);
	pb(stack_a, stack_b);
	if (second > third)
		sa(stack_a);
	if(level == TOP)
		pa(stack_b, stack_a);
	if(level == MIDDLE)
	{
		pa(stack_b, stack_a);
		sa(stack_a);
	}
	if(level == BOTTOM)
	{
		pa(stack_b, stack_a);
		ra(stack_a);
	}
	return;
}
