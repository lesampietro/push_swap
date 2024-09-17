/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:28:47 by lsampiet          #+#    #+#             */
/*   Updated: 2024/09/16 19:20:47 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int count_bits(int size)
{
	int max_bits;

	max_bits = 0;
	while (size != 0)
	{
		size /= 2;
		max_bits++;
	}
	return (max_bits);
}

// int	count_bits(int size)
// {
// 	int	max_bits;

// 	max_bits = 0;
// 	while (((size - 1) >> max_bits) != 0)
// 		max_bits++;
// 	return(max_bits);
// }

void	radix_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				i;
	int				j;
	int				size;
	
	i = 0;
	size = get_stack_size(stack_a);
	while (i < count_bits(size))
	{
		j = 0;
		while(j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
			{
				ra(stack_a);
			}
			else
				pb(stack_a, stack_b);
			j++;
		}
		while(*stack_b)
			pa(stack_b, stack_a);
		i++;
	}
}


