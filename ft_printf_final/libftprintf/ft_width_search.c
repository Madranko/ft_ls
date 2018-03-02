/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:24:49 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:25:21 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width_search(char *str, t_form *form, va_list ap)
{
	int		j;
	size_t	size;
	char	*to_convert;

	size = 0;
	j = 0;
	(*form).width = 0;
	if (str[j] == '*')
		return (str + ft_star(form, ap, 1));
	while (str[j] >= '0' && str[j] <= '9' &&
			str[j] != '\0' && ft_end_form(str[j]))
	{
		size++;
		j++;
	}
	if (size)
	{
		to_convert = (char *)malloc(sizeof(char) * size + 1);
		ft_strncpy(to_convert, str, size);
		to_convert[size] = '\0';
		(*form).width = (unsigned)ft_atoi(to_convert);
		ft_strdel(&to_convert);
	}
	return (str + size);
}
