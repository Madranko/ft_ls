/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:15:59 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:40:49 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_check_size(va_list ap)
{
	char	*str;

	str = ft_itoa_uns(va_arg(ap, size_t), 16);
	return (str);
}

int			ft_str_ptr(t_form *form, va_list ap)
{
	char	*nb_s;
	char	*to_free;
	int		ret;

	if ((*form).type == 'p')
	{
		nb_s = ft_check_size(ap);
		nb_s = ft_check_accur(*form, nb_s);
		to_free = nb_s;
		nb_s = ft_strjoin("0x", nb_s);
		ft_strdel(&to_free);
		nb_s = ft_check_width_num(*form, nb_s);
		nb_s = ft_check_flags_num(*form, nb_s);
		ft_putstr(nb_s);
		ret = (int)ft_strlen(nb_s);
		ft_strdel(&nb_s);
		return (ret);
	}
	return (0);
}
