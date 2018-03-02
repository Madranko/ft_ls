/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:09:57 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:10:38 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_check_size(t_form form, va_list ap)
{
	char	*str;

	str = NULL;
	if (form.type == 'O')
		str = ft_itoa_uns(va_arg(ap, long unsigned), 8);
	else if (!form.size)
		str = ft_itoa_base(va_arg(ap, unsigned), 8);
	else if (!ft_strcmp(form.size, "hh"))
		str = ft_itoa_base((unsigned char)va_arg(ap, unsigned), 8);
	else if (!ft_strcmp(form.size, "h"))
		str = ft_itoa_base((unsigned short)va_arg(ap, unsigned), 8);
	else if (!ft_strcmp(form.size, "ll"))
		str = ft_itoa_uns(va_arg(ap, long long unsigned), 8);
	else if (!ft_strcmp(form.size, "l"))
		str = ft_itoa_uns(va_arg(ap, long unsigned), 8);
	else if (!ft_strcmp(form.size, "j"))
		str = ft_itoa_uns((unsigned long)va_arg(ap, intmax_t), 8);
	else if (!ft_strcmp(form.size, "z"))
		str = ft_itoa_uns(va_arg(ap, size_t), 8);
	return (str);
}

static char		*ft_check_accur_octal(t_form form, char *str)
{
	char	*res;

	if (form.accur == -1 && !ft_strcmp(str, "0") && !form.flag_octorp)
	{
		res = ft_strdup("\0");
		ft_strdel(&str);
		return (res);
	}
	if (ft_strchr(str, '-'))
		form.accur++;
	if (form.accur == 0)
		return (str);
	if (form.accur > (int)ft_strlen(str))
		return (ft_add_accur(form, str));
	return (str);
}

int				ft_str_octal(t_form *form, va_list ap)
{
	char	*nb_s;
	int		ret;
	char	*to_free;

	if ((*form).type == 'o' || (*form).type == 'O')
	{
		nb_s = ft_check_size(*form, ap);
		if ((*form).flag_octorp && ft_strcmp(nb_s, "0"))
		{
			to_free = nb_s;
			nb_s = ft_strjoin("0", nb_s);
			ft_strdel(&to_free);
		}
		nb_s = ft_check_accur_octal(*form, nb_s);
		nb_s = ft_check_width_num(*form, nb_s);
		nb_s = ft_check_flags_num(*form, nb_s);
		ft_putstr(nb_s);
		ret = (int)ft_strlen(nb_s);
		ft_strdel(&nb_s);
		return (ret);
	}
	return (0);
}
