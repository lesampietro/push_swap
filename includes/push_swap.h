/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:05 by lsampiet          #+#    #+#             */
/*   Updated: 2024/09/04 19:37:02 by lsampiet         ###   ########.fr       */
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
};

// Doubly linked list struct
struct s_stack_node
{
	int					data;
	int					size;
	int					index;
	struct s_stack_node	*head;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
};

enum e_node_level
{
						TOP = 0,
						MIDDLE_01 = 1,
						MIDDLE_02 = 2,
						BOTTOM_01 = 3,
						BOTTOM_02 = 4,
};

// Functions to check arguments
int						get_size(char **args);
int						is_integer(char **args);
int						check_ascii(char **args);
char					**check_args(int argc, char **argv, t_data *data);
int						check_duplicates(int nbr, t_stack_node *stack_a);
int						is_empty(char **str);
int						is_sorted(t_stack_node **stack);

// Functions to create stacks
void					create_stack(t_stack_node **stack_a, char **argv, t_data *data);
t_stack_node			*create_node(int data);
void					get_stack_size(t_stack_node **stack);

// Functions to find nodes with specific positions or values
t_stack_node			*find_last_node(t_stack_node *stack_a);
t_stack_node			*find_smallest(t_stack_node **stack);
void					set_index(t_stack_node **stack);

// Functions to execute operations
void					sa(t_stack_node **stack_a);
void					sb(t_stack_node **stack_b);
void					ss(t_stack_node **stack_a, t_stack_node **stack_b);
void					ra(t_stack_node **stack_a);
void					rb(t_stack_node **stack_a);
void					rr(t_stack_node **stack_a, t_stack_node **stack_b);
void					rra(t_stack_node **stack_a);
void					rrb(t_stack_node **stack_a);
void					rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void					pa(t_stack_node **src_stack, t_stack_node **dest_stack);
void					pb(t_stack_node **src_stack, t_stack_node **dest_stack);

// Functions to sort the stack
void					sort_three(t_stack_node **stack_a);
int						sort_first(t_stack_node **stack_a);
void					sort_five(t_stack_node **stack_a, t_stack_node **stack_b);

// Error and free functions
int						arg_error(char **split_args);
void					free_array(char **args);
void					free_stack(t_stack_node *stack_a);

#endif