/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:57:55 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/05 18:27:36 by lsampiet         ###   ########.fr       */
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

void	free_stack(t_stack_node *stack_a)
{
	while (stack_a)
	{
		if (!stack_a->next)
			break;
		stack_a = stack_a->next;
		free(stack_a->prev);
	}
	free(stack_a);
}
