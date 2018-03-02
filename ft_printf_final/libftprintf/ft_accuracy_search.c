/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy_search.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 10:25:38 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:45:25 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_convert(t_form *form, char *str, int i)
{
	char	*to_convert;
	int		j;
	size_t	size;

	j = i;
	size = 0;
	while (str[j] >= '0' && str[j] <= '9' &&
			str[j] != '\0' && ft_end_form(str[j]))
	{
		size++;
		j++;
	}
	to_convert = (char *)malloc(sizeof(char) * (size + 1));
	to_convert[size] = '\0';
	ft_strncpy(to_convert, str + 1, size);
	(*form).accur = (unsigned)ft_atoi(to_convert);
	ft_strdel(&to_convert);
	return (str + size + 1);
}

char		*ft_accuracy_search(char *str, t_form *form, va_list ap)
{
	int		i;

	i = 0;
	(*form).accur = 0;
	if (str[i] != '.')
		return (str);
	if (str[i] == '.' && (str[i + 1] <= '0' || str[i + 1] > '9'))
	{
		if (str[i + 1] == '*')
			return (str + ft_star(form, ap, 2));
		(*form).accur = -1;
		if (str[i + 1] == '0')
			return (str + 2);
		else
			return (str + 1);
	}
	i++;
	return (ft_convert(form, str, i));
}
