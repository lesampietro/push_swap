/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:10 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/04 20:43:00 by lsampiet         ###   ########.fr       */
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

char	**check_args(int argc, char **argv)
{
	char	**split_args;
	
	split_args = NULL;
	if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		if (is_empty(split_args) == 1)
			arg_error(split_args);
		if (check_ascii(split_args) == 1)
			arg_error(split_args);
		if (is_integer(split_args) == 1)
			arg_error(split_args);
		return (split_args);
	}
	if (is_empty(argv + 1) == 1 || check_ascii(argv + 1) == 1 \
		|| is_integer(argv + 1) == 1)
			error();
	return (argv + 1);
}


int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			**new_argv;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	new_argv = check_args(argc, argv);
	create_stack(&stack_a, new_argv);
	return (0);
}
	// t_stack_node	*last_node;
	
	// stack_a = create_node(42);
	// stack_a->next = create_node(2);
	// while (stack_a)
	// {
	// 	ft_printf("%d\n", stack_a->data);
	// 	stack_a = stack_a->next;
	// }
	// // numbers = transform_args(argc, argv);