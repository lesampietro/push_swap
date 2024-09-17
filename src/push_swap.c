/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:10 by lsampiet          #+#    #+#             */
/*   Updated: 2024/09/16 23:43:32 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_stack_size(t_stack_node **stack)
{
	t_stack_node	*tmp;
	int				size;

	size = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

int	is_sorted(t_stack_node **stack)
{
	t_stack_node	*tmp;

	tmp = *stack;
	if (!tmp)
		return (1);
	while (tmp->next)
	{
		if(tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!(is_sorted(stack_a)))
	{	
		if (get_stack_size(stack_a) == 2)
			sa(stack_a);
		else if (get_stack_size(stack_a) == 3)
			sort_three(stack_a);
		else if (get_stack_size(stack_a) == 4 \
				|| get_stack_size(stack_a) == 5)
			sort_five_and_four(stack_a, stack_b);
		else
			radix_sort(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	// t_stack_node	*tmp_a; // tirar
	// t_stack_node	*tmp_b; // tirar
	t_data			data;
	char			**new_argv;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	new_argv = check_args(argc, argv, &data);
	create_stack(&stack_a, new_argv, &data);
	sort(&stack_a, &stack_b);
	// tmp_a = stack_a;
	// tmp_b = stack_b;
	// int i = 0;
	// while (tmp_a != NULL)
	// {
	// 	ft_printf("node %i data: %i - index: %i\n", i, tmp_a->data, tmp_a->index);
	// 	tmp_a = tmp_a->next;
	// 	i++;
	// }
	// i = 0;
	// while (tmp_b != NULL)
	// {
	// 	ft_printf("tmp_b 0%i: %d\n", i++, tmp_b->data);
	// 	tmp_b = tmp_b->next;
	// }
	if (data.split == true)
		free_array(new_argv);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
