/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:18:59 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:19:16 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_toupper(char *str)
{
	int		i;
	int		size;
	char	*new;

	size = (int)ft_strlen(str);
	new = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (str[i])
	{
		new[i] = ft_toupper(str[i]);
		i++;
	}
	new[i] = '\0';
	ft_strdel(&str);
	return (new);
}
