/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:57:55 by lsampiet          #+#    #+#             */
/*   Updated: 2024/06/18 15:08:27 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

// int	free_arr(int *arr)
// {
// 	int i;

// 	i = 0;
// 	while (arr[i] != NULL)
// 		free(paths[i++]);
// 	free(arr);
// }