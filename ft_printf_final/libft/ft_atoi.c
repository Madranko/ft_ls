/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:01:30 by mmotov            #+#    #+#             */
/*   Updated: 2017/11/08 16:39:12 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_miss_spaces(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	unsigned long int	res;
	int					i;
	int					negative;

	negative = 1;
	res = 0;
	i = ft_miss_spaces(str);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	if (res >= 9223372036854775807 && negative == -1)
		return (0);
	if (res >= 9223372036854775807 && negative == 1)
		return (-1);
	res *= negative;
	return (res);
}
