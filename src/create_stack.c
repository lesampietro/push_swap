/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:37:58 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/03 22:08:07 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//interpretar argvs que vierem dentro de " "

t_stack	*create_node(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_stack	append_node(t_stack **stack_a, int data)
{
	t_stack	*node;
	t_stack	*last_node;
	
	node = create_node(data);
	if (!node)
		stack_error(stack_a);
	if (*stack_a == NULL)
	{
		*stack_a = node;
		if (!*stack_a)
			stack_error(stack_a);
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack_a);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	create_stack(t_stack **stack_a, char **argv)
{
	int nbr;

	while (*argv)
	{
		nbr = ft_atoi(*argv);
		if (check_duplicates(nbr, *stack_a) == 1)
			stack_error(stack_a);
		append_node(stack_a, nbr);
		argv++;
	}
}
