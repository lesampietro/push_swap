/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:57:55 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/04 17:26:39 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	arg_error(char **split_args)
{
	ft_putstr_fd("Error\n", 2);
	free_array(split_args);
	exit(1);
}

void	free_array(char **args)
{
	int	i;
	
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

// void	stack_error(t_stack_node **stack_a)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	while (*stack_a)
// 	{
// 		free(stack_a);
// 		*stack_a = *(stack_a)->next;
// 	}
// 	stack_a = NULL;
// 	exit(1);
// }
