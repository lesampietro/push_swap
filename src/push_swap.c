/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:10 by lsampiet          #+#    #+#             */
/*   Updated: 2024/07/05 16:51:05 by lsampiet         ###   ########.fr       */
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
	int		x;
	char	**split_args;
	long	nbr;
	
	split_args = NULL;
	nbr = 0;
	if (argc == 1)
		ft_error();
	x = 1;
	i = 0;
	while (argv[x])
	{
		split_args = ft_split(argv[x], ' ');
		if (is_empty(split_args) == 1)
			ft_error();
		free_array(split_args);
		x++;
	}
}

int	main(int argc, char **argv)
{

	check_argc(argc, argv);
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