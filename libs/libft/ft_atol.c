/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:54:47 by lsampiet          #+#    #+#             */
/*   Updated: 2024/07/05 17:09:16 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace_l(char c)
{	
	if ((c >= 9 && c <= 13) || (c == ' '))
		return (1);
	return (0);
}

int	ft_issign_l(char c)
{
	if ((c == '-') || (c == '+'))
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	long	res;
	long	sign;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace_l(nptr[i]))
		i++;
	if (ft_issign_l(nptr[i]))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
		if (ft_issign_l(nptr[i]) || ft_isspace_l(nptr[i]))
			return (0);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
