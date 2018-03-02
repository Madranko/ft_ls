/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:23:58 by mmotov            #+#    #+#             */
/*   Updated: 2018/01/01 13:23:34 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_check_size_uns_long(t_form form, va_list ap)
{
	char	*str;

	str = NULL;
	if (!form.size)
		str = ft_itoa_uns(va_arg(ap, long unsigned), 10);
	else if (!ft_strcmp(form.size, "hh"))
		str = ft_itoa_uns(va_arg(ap, long unsigned), 10);
	else if (!ft_strcmp(form.size, "h"))
		str = ft_itoa_uns((unsigned long int)va_arg(ap, long int), 10);
	else if (!ft_strcmp(form.size, "ll"))
		str = ft_itoa_uns(va_arg(ap, long long unsigned), 10);
	else if (!ft_strcmp(form.size, "l"))
		str = ft_itoa_uns(va_arg(ap, long unsigned), 10);
	else if (!ft_strcmp(form.size, "j"))
		str = ft_itoa_uns(va_arg(ap, uintmax_t), 10);
	else if (!ft_strcmp(form.size, "z"))
		str = ft_itoa_uns(va_arg(ap, size_t), 10);
	return (str);
}

static char	*ft_check_size_uns(t_form form, va_list ap)
{
	char	*str;

	str = NULL;
	if (form.type == 'U')
		return (ft_check_size_uns_long(form, ap));
	if (!form.size)
		str = ft_itoa_base(va_arg(ap, unsigned), 10);
	else if (!ft_strcmp(form.size, "hh"))
		str = ft_itoa_base((unsigned char)va_arg(ap, int), 10);
	else if (!ft_strcmp(form.size, "h"))
		str = ft_itoa_base((unsigned short int)va_arg(ap, int), 10);
	else if (!ft_strcmp(form.size, "ll"))
		str = ft_itoa_uns(va_arg(ap, long long unsigned), 10);
	else if (!ft_strcmp(form.size, "l"))
		str = ft_itoa_uns(va_arg(ap, long unsigned), 10);
	else if (!ft_strcmp(form.size, "j"))
		str = ft_itoa_uns(va_arg(ap, uintmax_t), 10);
	else if (!ft_strcmp(form.size, "z"))
		str = ft_itoa_uns(va_arg(ap, size_t), 10);
	return (str);
}

int			ft_str_unsigned(t_form *form, va_list ap)
{
	char	*nb_s;
	int		ret;

	if ((*form).type == 'u' || (*form).type == 'U')
	{
		nb_s = ft_check_size_uns(*form, ap);
		nb_s = ft_check_apostrophe(nb_s, *form);
		nb_s = ft_check_accur(*form, nb_s);
		nb_s = ft_check_width_num(*form, nb_s);
		nb_s = ft_check_flags_num(*form, nb_s);
		ft_putstr(nb_s);
		ret = (int)ft_strlen(nb_s);
		ft_strdel(&nb_s);
		return (ret);
	}
	return (0);
}
