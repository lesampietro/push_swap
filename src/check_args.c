/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:37:58 by lsampiet          #+#    #+#             */
/*   Updated: 2024/09/13 20:04:50 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_empty(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == '\0')
			return (1);
		i++;
	}
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

int	check_duplicates(int nbr, t_stack_node *stack_a)
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

char	**check_args(int argc, char **argv, t_data *data)
{
	char	**split_args;
	
	split_args = NULL;
	data->split = false;
	if(is_empty(&argv[1]) == 1)
		exit(write(2, "Error\n", 6)/6);
	if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		if (is_empty(split_args) == 1)
			arg_error(split_args);
		if (check_ascii(split_args) == 1)
			arg_error(split_args);
		if (is_integer(split_args) == 1)
			arg_error(split_args);
		data->split = true;
		return (split_args);
	}
	if (is_empty(argv + 1) == 1 || check_ascii(argv + 1) == 1 \
		|| is_integer(argv + 1) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (argv + 1);
}
