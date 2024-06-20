/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:10 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/19 21:03:28 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int first_time(int status)
{
	static int	first;

	if (status != CONSULT)
		first = status;
	return (first);
}

int	check_duplicates(int *int_args)
{
	int	i;
	int	j;

	i = 0;
	while (int_args[i])
	{
		j = i + 1;
		while (int_args[j])
		{
			if (int_args[i] == int_args[j])
				ft_error();
			j++;
		}
		i++;
	}
	return (1);
}

void	check_ascii(char *str)
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
	check_ascii(++str);
}

int	*check_args(int size, char **argv, int *int_args)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++i <= size)
	{
		check_ascii(argv[i]);
		first_time(OFF);
		int_args[++j] = ft_atoi(argv[i]);
	}
	if (!check_duplicates(int_args))
		ft_error();
	return(int_args);
}

int	main(int argc, char **argv)
{
	t_stack	s_a;

	s_a.stack = malloc(sizeof(int) * (argc - 1));
	s_a.size = argc - 1;
	if (!s_a.stack)
	{
		free(s_a.stack);
		return (1);
	}
	s_a.stack = check_args(s_a.size, argv, s_a.stack);
	free(s_a.stack);
	return (0);
}