/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:10 by lsampiet          #+#    #+#             */
/*   Updated: 2024/09/04 17:54:15 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//checa se há um número menor em algum dos nós da lista, com um endereço de target passado a partir da função de chamada
t_stack_node	*find_smallest(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*target;

	tmp = *stack;
	target = NULL;
	while (tmp != NULL)
	{
		if ((target == NULL || target->data > tmp->data) && tmp->index == -1)
			target = tmp;
		tmp = tmp->next;
	}
	return (target);
}

void	set_index(t_stack_node **stack)
{
	t_stack_node	*min_node;
	int				i;

	i = 0;
	while (i < (*stack)->size)
	{
		min_node = find_smallest(stack);
		min_node->index = i;
		i++;
	}
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

void	get_stack_size(t_stack_node **stack)
{
	t_stack_node	*tmp;
	int				size;

	size = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		tmp = (*tmp).next;
		size++;
	}
	(*stack)->size = size;
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	t_stack_node	*tmp_a; // tirar
	t_stack_node	*tmp_b; // tirar
	t_data			data;
	char			**new_argv;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	new_argv = check_args(argc, argv, &data);
	create_stack(&stack_a, new_argv, &data);
	get_stack_size(&stack_a);
	if (!(is_sorted(&stack_a)))
	{	
		if (stack_a->size == 2)
			sa(&stack_a);
		if (stack_a->size == 3)
			sort_three(&stack_a);
		// if (stack_a->size == 4 || stack_a->size == 5)
		// 	sort_five(&stack_a, &stack_b);
	// else
	// 	sort(&stack_a, &stack_b);
	}
	set_index(&stack_a);
	tmp_a = stack_a;
	tmp_b = stack_b;
	int i = 0;
	while (tmp_a != NULL)
	{
		ft_printf("tmp_a 0%i: %d\n", i++, tmp_a->index);
		tmp_a = tmp_a->next;
	}
	i = 0;
	while (tmp_b != NULL)
	{
		ft_printf("tmp_b 0%i: %d\n", i++, tmp_b->index);
		tmp_b = tmp_b->next;
	}
	if (data.split == true)
		free_array(new_argv);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}