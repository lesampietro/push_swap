/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:05 by lsampiet          #+#    #+#             */
/*   Updated: 2024/07/05 18:22:45 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_data t_data;
typedef struct s_stack t_stack;

// Doubly linked list struct
struct s_stack
{
	int			data;
	struct node	*prev;
	struct node	*next;
};

struct s_data
{
	int			*stack;
	int			size;
};

enum e_legible
{
	CONSULT = -1,
	OFF,
	ON,
};

// Functions to check arguments
int				get_size(char **args);
int				is_integer(char **split_args);
int				check_ascii(char **args);
int				*check_args(int size, char **argv, int *int_args);
void			check_argc(int argc, char **argv);
int				check_duplicates(char **split_args);
int				is_empty(char **str);
	// static int	first_time(int status);

	// Functions to execute operations

	// Functions to sort the stack

	// Functions to display the stack

	// Error and free functions
int				ft_arg_error(char **split_args);
void			free_array(char **args);

#endif