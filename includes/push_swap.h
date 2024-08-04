/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:05 by lsampiet          #+#    #+#             */
/*   Updated: 2024/08/04 16:54:31 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/includes/ft_printf.h"
# include <limits.h>
# include <stdbool.h> //criar as flags que ajudam a printar a lista de comandos


// INT_MAX = 2147483647;
// INT_MIN = -2147483648;

typedef struct s_data t_data;
typedef struct s_stack_node t_stack_node;

// Doubly linked list struct
struct s_stack_node
{
	int					data;
	int					index;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
};

struct s_data
{
	int					*stack;
	int					size;
};

enum e_legible
{
	CONSULT = -1,
	OFF,
	ON,
};

// Functions to check arguments
int						get_size(char **args);
int						is_integer(char **args);
int						check_ascii(char **args);
int						*check_args(int size, char **argv, int *int_args);
void					check_argc(int argc, char **argv);
int						check_duplicates(int nbr, t_stack_node *stack_a);
int						is_empty(char **str);

// Functions to create stacks
void					create_stack(t_stack_node **stack_a, char **argv);
t_stack_node			*create_node(int data);

// Functions to execute operations

// Functions to sort the stack

// Functions to display the stack

// Error and free functions
int						arg_error(char **split_args);
void					free_array(char **args);
void					stack_error(t_stack_node *stack_a);

#endif