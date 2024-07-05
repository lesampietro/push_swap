/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:10 by lsampiet          #+#    #+#             */
/*   Updated: 2024/07/05 18:24:28 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//dividir a main em funções para checagem de quantidade de argumentos, checagem de argumentos e execução de operações

int	get_size(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	is_empty(char **str)
{
	if (!*str)
		return (1);
	return (0);
}

void	check_argc(int argc, char **argv)
{
	int		i;
	char	**split_args;
	
	i = 0;
	split_args = NULL;
	if (argc == 1)
		ft_putendl_fd("Error", 2);
	while (argv[++i])
	{
		split_args = ft_split(argv[i], ' ');
		if (is_empty(split_args) == 1)
			ft_arg_error(split_args);
		if (check_ascii(split_args) == 1)
			ft_arg_error(split_args);
		if (is_integer(split_args) == 1)
			ft_arg_error(split_args);
		free_array(split_args);
	}	
}

int	main(int argc, char **argv)
{
	// int		*numbers;
	
	check_argc(argc, argv);
	// numbers = transform_args(argc, argv);
	return (0);
}

	// t_data	s_a;
	// if (argc == 1 || (argc == 2 && !argv[1][0]))
	// {
	// 	ft_error();
	// 	free(s_a.stack);
	// 	free(args);
	// }
	// else if (argc == 2)
	// {
	// 	args = ft_split(argv[1], ' ');
	// 	if (!args)
	// 		ft_error();
	// 	s_a.size = get_size(args);
	// 	s_a.stack = malloc(sizeof(int) * (s_a.size));
	// 	s_a.stack = check_args(s_a.size, args, s_a.stack);
	// }
	// else
	// {
	// 	s_a.size = (argc - 1);
	// 	s_a.stack = malloc(sizeof(int) * (s_a.size));
	// 	if (!s_a.stack)
	// 		return (1);
	// 	s_a.stack = check_args(s_a.size, argv + 1, s_a.stack);
	// }
	// if (args)
	// 	free_array(args);
	// free(s_a.stack);