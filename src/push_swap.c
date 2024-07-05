/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:10 by lsampiet          #+#    #+#             */
/*   Updated: 2024/07/04 22:38:31 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_size(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_data	s_a;
	char	**args;

	args = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		ft_error();
		free(s_a.stack);
		free(args);
	}
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			ft_error();
		s_a.size = get_size(args);
		s_a.stack = malloc(sizeof(int) * (s_a.size));
		s_a.stack = check_args(s_a.size, args, s_a.stack);
	}
	else
	{
		s_a.size = (argc - 1);
		s_a.stack = malloc(sizeof(int) * (s_a.size));
		if (!s_a.stack)
			return (1);
		s_a.stack = check_args(s_a.size, argv + 1, s_a.stack);
	}
	if (args)
		free_array(args);
	free(s_a.stack);
	return (0);
}