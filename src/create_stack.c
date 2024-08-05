/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:37:58 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/05 19:20:33 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*create_node(int data)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_stack_node	*find_last_node(t_stack_node *stack_a)
{
	if (!stack_a)
		return (NULL);
	while (stack_a->next != NULL)
		stack_a = stack_a->next;
	return (stack_a);
}

t_stack_node	*append_node(t_stack_node **stack_a, int data)
{
	t_stack_node	*node;
	t_stack_node	*last_node;
	
	if(!stack_a)
		return (NULL);
	node = create_node(data);
	if (!node)
		return (NULL);
	if (!(*stack_a))
	{
		*stack_a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack_a);
		last_node->next = node;
		node->prev = last_node;
	}
	return (node);
}

void	create_stack(t_stack_node **stack_a, char **argv, t_data *data)
{
	int	nbr;
	int	i;

	i = 0;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		if (check_duplicates(nbr, *stack_a) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(*stack_a);
			if(data->split == true)
				free_array(argv);
			exit (1);
		}
		append_node(stack_a, nbr);
		i++;
	}
}