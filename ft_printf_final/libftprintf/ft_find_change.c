/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_change.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:02:48 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:03:02 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_find_change(char *str, char old, char new)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == old)
			str[i] = new;
		i++;
	}
	return (str);
}
