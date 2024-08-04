/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:10 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/03 21:36:02 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// colocar os números em nós da lista e checar se tem: apenas um nó, e se há duplicatas

int	get_size(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}


void	check_argc(int argc, char **argv)
{
	int		i;
	char	**split_args;
	
	i = 0;
	split_args = NULL;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	while (argv[++i])
	{
		split_args = ft_split(argv[i], ' ');
		if (is_empty(split_args) == 1)
			arg_error(split_args);
		if (check_ascii(split_args) == 1)
			arg_error(split_args);
		if (is_integer(split_args) == 1)
			arg_error(split_args);
		free_array(split_args);
	}	
}


int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_argc(argc, argv);
	create_stack(&stack_a, argv + 1);
	return (0);
}
	// t_stack	*last_node;
	
	// stack_a = create_node(42);
	// stack_a->next = create_node(2);
	// while (stack_a)
	// {
	// 	ft_printf("%d\n", stack_a->data);
	// 	stack_a = stack_a->next;
	// }
	// // numbers = transform_args(argc, argv);