/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:57:55 by lsampiet          #+#    #+#             */
/*   Updated: 2024/07/05 18:12:58 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_arg_error(char **split_args)
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