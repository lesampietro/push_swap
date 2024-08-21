/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:53:42 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/21 15:01:16 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/push_swap.h"

// void	push_element(t_stack_node *smaller, t_stack_node **stack_a, t_stack_node **stack_b)
// {
// 	if(smaller == *stack_a)
// 		pb(stack_a, stack_b);
// 	else if(smaller == (*stack_a)->next)
// 	{
// 		sa(stack_a);
// 		pb(stack_a, stack_b);
// 	}
// 	else if (smaller == (*stack_a)->next->next)
// 	{
// 		ra(stack_a);
// 		sa(stack_a);
// 		pb(stack_a, stack_b);
// 	}
// 	else if (smaller == (*stack_a)->next->next->next)
// 	{
// 		rra(stack_a);
// 		rra(stack_a);
// 		pb(stack_a, stack_b);
// 	}
// 	else
// 	{
// 		rra(stack_a);
// 		pb(stack_a, stack_b);
// 	}
// }

// void	push_smaller(t_stack_node **stack_a, t_stack_node **stack_b)
// {
// 	int				i;
// 	int				stack_size;
// 	t_stack_node	*smaller;
// 	t_stack_node	*tmp;
	
// 	i = 0;
// 	smaller = *stack_a;
// 	tmp = *stack_a;
// 	stack_size = get_stack_size(stack_a);
// 	while(i < stack_size)
// 	{
// 		if ((tmp)->next && 
// 			((smaller)->data > (tmp)->next->data))
// 			smaller = (tmp)->next;
// 		tmp = (tmp)->next;
// 		i++;
// 	}
// 	push_element(smaller, stack_a, stack_b);
// }

// void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
// {
// 	push_smaller(stack_a, stack_b);
// 	push_smaller(stack_a, stack_b);
// 	sort_three(stack_a);
// 	pa(stack_b, stack_a);
// 	pa(stack_b, stack_a);
// 	return;
// }