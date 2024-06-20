/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:05 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/18 21:45:04 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack t_stack;

struct s_stack
{
	int	*stack;
	int	size;
};

enum e_legible
{
	CONSULT = -1,
	OFF,
	ON,
};

int	ft_error(void);

#endif