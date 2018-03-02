/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_arr_strlen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:03:46 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:04:06 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_full_arr_strlen(unsigned char **arr)
{
	int		i;
	int		j;
	size_t	size;

	size = 0;
	i = 0;
	j = 0;
	while (arr[i])
	{
		while (arr[i][j])
		{
			size++;
			j++;
		}
		j = 0;
		i++;
	}
	return (size);
}
