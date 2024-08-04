/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:37:58 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/04 14:03:27 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_empty(char **str)
{
	if (!*str)
		return (1);
	return (0);
}

int	check_ascii(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '-' || args[i][j] == '+')
			{
				j++;
				if (!args[i][j])
					return (1);
			}
			while (ft_isdigit(args[i][j]))
				j++;
			if (args[i][j])
				return (1);
		}
		i++;
	}
	return (0);
}

int	is_integer(char **args)
{
	int		i;
	long	nbr;

	i = 0;
	while (args[i])
	{
		nbr = ft_atol(args[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int check_duplicates(int nbr, t_stack_node *stack_a)
{
	if (stack_a == NULL)
		return (0);
	while (stack_a)
	{
		if (stack_a->data == nbr)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

