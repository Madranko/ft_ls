/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:23:14 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:23:47 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned char	*ft_check_size(t_form form, va_list ap)
{
	unsigned char	*uni_str;

	if (form.size && !ft_strcmp(form.size, "hh"))
		uni_str = ft_make_unicode((unsigned short)va_arg(ap, int));
	else if (form.size && !ft_strcmp(form.size, "h"))
		uni_str = ft_make_unicode(va_arg(ap, unsigned int));
	else
		uni_str = ft_make_unicode(va_arg(ap, unsigned int));
	return (uni_str);
}

int						ft_str_unicode(t_form *form, va_list ap)
{
	char	*str;
	int		res;

	if ((*form).type == 'C')
	{
		str = (char *)ft_check_size(*form, ap);
		if (str[0] == 0)
		{
			ft_strdel(&str);
			return (ft_print_null(*form));
		}
		str = ft_check_width_str(*form, str);
		ft_putstr(str);
		res = (int)ft_strlen(str);
		ft_strdel(&str);
		return (res);
	}
	return (0);
}
