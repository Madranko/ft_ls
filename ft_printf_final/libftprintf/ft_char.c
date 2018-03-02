/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 09:54:44 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:43:52 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_check_size(va_list ap)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[1] = '\0';
	str[0] = (char)va_arg(ap, int);
	return (str);
}

static int		ft_print(char *str, t_form form)
{
	int		ret;

	str = ft_check_width_str(form, str);
	ft_putstr(str);
	ret = (int)ft_strlen(str);
	ft_strdel(&str);
	return (ret);
}

int				ft_str_char(t_form *form, va_list ap)
{
	char	*str;

	if ((*form).type == 'c')
	{
		if ((*form).size && !ft_strcmp((*form).size, "l"))
		{
			(*form).type = 'C';
			return (ft_str_unicode(form, ap));
		}
		if (!(str = ft_check_size(ap)))
		{
			ft_strdel(&str);
			return (0);
		}
		if (str[0] == '\0')
		{
			ft_strdel(&str);
			return (ft_print_null(*form));
		}
		return (ft_print(str, *form));
	}
	return (0);
}
