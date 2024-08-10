/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:05 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/10 17:36:14 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/includes/ft_printf.h"
# include <limits.h>
# include <stdbool.h> //criar as flags que ajudam a printar a lista de comandos

typedef struct s_data t_data;
typedef struct s_stack_node t_stack_node;

struct s_data
{
	bool				split;
	int					size;
};

// Doubly linked list struct
struct s_stack_node
{
	int					data;
	int					index;
	struct s_stack_node	*head;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
};

// Functions to check arguments
int						get_size(char **args);
int						is_integer(char **args);
int						check_ascii(char **args);
char					**check_args(int argc, char **argv, t_data *data);
int						check_duplicates(int nbr, t_stack_node *stack_a);
int						is_empty(char **str);

// Functions to create stacks
void					create_stack(t_stack_node **stack_a, char **argv, t_data *data);
t_stack_node			*create_node(int data);
int						get_stack_size(t_stack_node *stack_a, t_data *data);

// Functions to execute operations
static void				swap(t_stack_node **stack_a);
//static functions are only visible inside the file they are declared - for performance optimization purposes
void					sa(t_stack_node **stack_a);
void					sb(t_stack_node **stack_b);
void					ss(t_stack_node **stack_a, t_stack_node **stack_b);

	// Functions to sort the stack

	// Functions to display the stack

	// Error and free functions
	int arg_error(char **split_args);
void					free_array(char **args);
void					free_stack(t_stack_node *stack_a);

#endif