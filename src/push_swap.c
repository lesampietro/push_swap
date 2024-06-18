/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:10 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/18 19:04:13 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	push_swap

static int first_time(int status)
{
	static int	first;

	if (status != CONSULT)
		first = status;
	return (first);
}

void	check_str(char *str)
{
	if	(!*str && !first_time(CONSULT))
		ft_error();
	else if (!*str)
		return ;
	first_time(ON);
	if (*str == '-' || *str == '+') {
		++str;
		if (!*str)
			ft_error();
	}
	if (!ft_isdigit(*str) || ft_strncmp(str, "", 1) == 0)
			ft_error();
	check_str(++str);
}

int	*check_args(int argc, char **argv, int *int_args)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++i <= argc)
	{
		check_str(argv[i]);
		first_time(OFF);
		int_args[++j] = ft_atoi(argv[i]);
	}
	return(int_args);
}

int	main(int argc, char **argv)
{
	int	*int_args;

	int_args = malloc(sizeof(int) * (argc - 1));
	if (!int_args)
	{
		free(int_args);
		return (1);
	}
	int_args = check_args((argc - 1), argv, int_args);
	free(int_args);
	return (0);
}