/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:37:58 by lsampiet          #+#    #+#             */
/*   Updated: 2024/07/27 17:25:31 by lsampiet         ###   ########.fr       */
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
	j = 0;
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
			if (!ft_isdigit(args[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_integer(char **split_args)
{
	int		i;
	long	nbr;

	i = 0;
	while (split_args[i])
	{
		nbr = ft_atol(split_args[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	check_duplicates(char **split_args)
{
	int		i;
	int		j;
	long	nbr_01;
	long	nbr_02;

	i = 0;
	nbr_01 = 0;
	nbr_02 = 0;
	while (split_args[i])
	{
		j = i + 1;
		nbr_01 = ft_atol(split_args[i]);
		while (split_args[j])
		{
			nbr_02 = ft_atol(split_args[j]);
			if (nbr_01 == nbr_02)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
