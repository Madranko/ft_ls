/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:04:21 by mmotov            #+#    #+#             */
/*   Updated: 2018/01/01 13:56:11 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_check_size_lx(t_form form, va_list ap)
{
	char	*str;

	str = NULL;
	if (!form.size)
		str = ft_itoa_uns(va_arg(ap, unsigned), 16);
	else if (!ft_strcmp(form.size, "hh"))
		str = ft_itoa_base((unsigned char)va_arg(ap, long unsigned), 16);
	else if (!ft_strcmp(form.size, "h"))
		str = ft_itoa_base((unsigned short)va_arg(ap, unsigned int), 16);
	else if (!ft_strcmp(form.size, "ll"))
		str = ft_itoa_uns(va_arg(ap, long long unsigned), 16);
	else if (!ft_strcmp(form.size, "l"))
		str = ft_itoa_uns(va_arg(ap, long unsigned), 16);
	else if (!ft_strcmp(form.size, "j"))
		str = ft_itoa_uns(va_arg(ap, uintmax_t), 16);
	else if (!ft_strcmp(form.size, "z"))
		str = ft_itoa_uns(va_arg(ap, size_t), 16);
	return (str);
}

static char		*ft_check_size(t_form form, va_list ap)
{
	char	*str;

	str = NULL;
	if (form.type == 'X')
		str = ft_check_size_lx(form, ap);
	else if (!form.size)
		str = ft_itoa_base(va_arg(ap, unsigned int), 16);
	else if (!ft_strcmp(form.size, "hh"))
		str = ft_itoa_base((unsigned char)va_arg(ap, int), 16);
	else if (!ft_strcmp(form.size, "h"))
		str = ft_itoa_base((unsigned short)va_arg(ap, unsigned int), 16);
	else if (!ft_strcmp(form.size, "ll"))
		str = ft_itoa_uns(va_arg(ap, long long unsigned), 16);
	else if (!ft_strcmp(form.size, "l"))
		str = ft_itoa_uns(va_arg(ap, long unsigned), 16);
	else if (!ft_strcmp(form.size, "j"))
		str = ft_itoa_uns(va_arg(ap, uintmax_t), 16);
	else if (!ft_strcmp(form.size, "z"))
		str = ft_itoa_uns(va_arg(ap, size_t), 16);
	return (str);
}

static char		*ft_join_format(char *nb_s)
{
	char	*to_free;

	to_free = nb_s;
	nb_s = ft_strjoin("0x", nb_s);
	ft_strdel(&to_free);
	return (nb_s);
}

int				ft_str_hexal(t_form *form, va_list ap)
{
	char	*nb_s;
	int		ret;

	if ((*form).type == 'x' || (*form).type == 'X')
	{
		nb_s = ft_check_size(*form, ap);
		if (!ft_strcmp(nb_s, "0"))
			(*form).flag_octorp = 0;
		nb_s = ft_check_accur(*form, nb_s);
		if ((*form).flag_octorp && ft_strcmp(nb_s, "0") && ft_strcmp(nb_s, ""))
			nb_s = ft_join_format(nb_s);
		nb_s = ft_check_width_num(*form, nb_s);
		nb_s = ft_check_flags_num(*form, nb_s);
		if ((*form).type == 'X')
			nb_s = ft_str_toupper(nb_s);
		ft_putstr(nb_s);
		ret = (int)ft_strlen(nb_s);
		ft_strdel(&nb_s);
		return (ret);
	}
	return (0);
}
