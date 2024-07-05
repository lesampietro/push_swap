/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:37:58 by lsampiet          #+#    #+#             */
/*   Updated: 2024/07/05 17:36:00 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// INT_MAX = 2147483647;
// INT_MIN = -2147483648;
// usar atoL (a to long) para converter string para long

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

// int	check_duplicates(int *int_args, int size)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			if (int_args[i] == int_args[j])
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// void	check_ascii(char *str, int *int_args)
// {
// 	if (str == NULL || str[0] == '\0')
// 		return ;
// 	if (*str == '-' || *str == '+')
// 	{
// 		++str;
// 		if (!*str)
// 		{
// 			free(int_args);
// 			ft_error();
// 		}
// 	}
// 	if (!ft_isdigit(*str))
// 	{
// 		free(int_args);
// 		ft_error();
// 	}
// 	check_ascii(++str, int_args);
// }

// int	*check_args(int size, char **args, int *int_args)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = -1;
// 	while (i < size)
// 	{
// 		check_ascii(args[i], int_args);
// 		int_args[++j] = ft_atoi(args[i]);
// 		ft_printf("args: %i\n", int_args[j]);
// 		i++;
// 	}
// 	if (check_duplicates(int_args, size) == 1)
// 	{
// 		if (args)
// 			free_array(args);
// 		free(int_args);
// 		ft_error();
// 	}
// 	// Criar validação que dá free na stack se algo der errado
// 	// is_integer(size, args);
// 	return (int_args);
// }