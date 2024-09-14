/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:28:47 by lsampiet          #+#    #+#             */
/*   Updated: 2024/09/13 21:04:15 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_bits(t_stack_node **stack_a)
{
	static int	max_bits;

	if(max_bits != 0)
		return(max_bits);
	while ((((*stack_a)->size - 1) >> max_bits) != 0)
		++max_bits;
	return(max_bits);
}

void print_stack(t_stack_node *a)
{
	while (a)
	{
		ft_printf("a: %d\n", a->index);
		a = a->next;
	}
}

void	radix_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*tmp_a;
	t_stack_node	*tmp_b;
	int				empty_b;
	int				i;
	int				j;
	int				size;
	
	i = -1;
	empty_b = 0;
	get_stack_size(stack_a);
	size = (*stack_a)->size;
	while (++i < count_bits(stack_a))
	{
		tmp_a = *stack_a;
		tmp_b = *stack_b;
		j = 0;
		while(j < size)
		{
			if (((tmp_a->index >> i) & 1) == 1)
			{
				ra(&tmp_a);
			}
			else
			{
				pb(&tmp_a, &tmp_b);
				empty_b++;
			}
			j++;
		}
		// ft_printf("%i\n", empty_b);
		//ft_printf("antes\n");
		//print_stack(*stack_a);
		while(empty_b-- > 0)
			pa(&tmp_b, &tmp_a);
		//ft_printf("depois\n");
		//print_stack(*stack_a);
	}
}


