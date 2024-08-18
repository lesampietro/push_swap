/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:10 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/18 16:55:52 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_stack_size(t_stack_node **stack_a)
{
	t_stack_node	*tmp;
	int				size;

	size = 0;
	tmp = *stack_a;
	while (tmp != NULL)
	{
		tmp = (*tmp).next;
		size++;
	}
	return (size);
}

char	**check_args(int argc, char **argv, t_data *data)
{
	char	**split_args;
	
	split_args = NULL;
	data->split = false;
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

int	main(int argc, char **argv)
{
	t_stack_node *stack_a;
	t_stack_node *stack_b;
	t_data data;
	char **new_argv;

	stack_a = NULL;
	// stack_b = NULL;
	stack_b = malloc(sizeof(t_stack_node));
	stack_b->next = malloc(sizeof(t_stack_node));
	stack_b->next->next = malloc(sizeof(t_stack_node));
	stack_b->data = 42;
	stack_b->next->data = 21;
	stack_b->next->next->data = -31;
	stack_b->head = stack_b;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	new_argv = check_args(argc, argv, &data);
	create_stack(&stack_a, new_argv, &data);
	// if(get_stack_size(&stack_a) == 3)
	// 	sort_three(&stack_a);
	// else if(get_stack_size(&stack_a) == 5)
	// 	sort_five(&stack_a, &stack_b);
	// else
	// 	sort(&stack_a, &stack_b);
	// sa(&stack_a);
	pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// sort(&a, &b);
	if (data.split == true)
		free_array(new_argv);
	free_stack(stack_a);
	return (0);
}