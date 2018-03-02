/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_apostrophe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 13:47:42 by mmotov            #+#    #+#             */
/*   Updated: 2018/01/01 13:55:03 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_place_comma(char *new, int new_size, char *str)
{
	int		to_place;
	int		j;

	to_place = new_size - 4;
	new_size--;
	j = (int)ft_strlen(str) - 1;
	while (new_size >= 0)
	{
		if (to_place == new_size)
		{
			new[new_size] = ',';
			new_size--;
			to_place = to_place - 4;
		}
		else
		{
			new[new_size] = str[j];
			new_size--;
			j--;
		}
	}
	ft_strdel(&str);
	return (new);
}

char		*ft_check_apostrophe(char *str, t_form form)
{
	int		count;
	int		new_size;
	char	*new;

	if (form.flag_apost && ft_strlen(str) / 3)
	{
		count = (int)ft_strlen(str) / 3;
		if (ft_strlen(str) % 3 == 0)
			count--;
		new_size = (int)ft_strlen(str) + count;
		new = (char *)malloc(sizeof(char) * (new_size + 1));
		new = ft_memset(new, '0', (size_t)new_size);
		new[new_size] = '\0';
		return (ft_place_comma(new, new_size, str));
	}
	return (str);
}
