/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:05:18 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:05:59 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_check_size_int(t_form form, va_list ap)
{
	char	*str;

	str = NULL;
	if (!form.size)
		str = ft_itoa_base(va_arg(ap, int), 10);
	else if (!ft_strcmp(form.size, "hh"))
		str = ft_itoa_base((signed char)va_arg(ap, int), 10);
	else if (!ft_strcmp(form.size, "h"))
		str = ft_itoa_base((short int)va_arg(ap, int), 10);
	else if (!ft_strcmp(form.size, "ll"))
		str = ft_itoa_base(va_arg(ap, long long int), 10);
	else if (!ft_strcmp(form.size, "l"))
		str = ft_itoa_base(va_arg(ap, long int), 10);
	else if (!ft_strcmp(form.size, "j"))
		str = ft_itoa_base(va_arg(ap, intmax_t), 10);
	else if (!ft_strcmp(form.size, "z"))
		str = ft_itoa_base(va_arg(ap, intmax_t), 10);
	return (str);
}

static int		ft_print(t_form form, char *nb_s)
{
	int		ret;

	nb_s = ft_check_width_num(form, nb_s);
	nb_s = ft_check_flags_num(form, nb_s);
	if (form.flag_space && form.flag_zero && nb_s[0] != '-')
		nb_s[0] = ' ';
	nb_s = ft_push_char(nb_s, '+', '0');
	ft_putstr(nb_s);
	ret = (int)ft_strlen(nb_s);
	ft_strdel(&nb_s);
	return (ret);
}

int				ft_str_integers(t_form *form, va_list ap)
{
	char	*nb_s;
	char	*to_free;

	if ((*form).type == 'd' || (*form).type == 'i')
	{
		nb_s = ft_check_size_int(*form, ap);
		nb_s = ft_check_apostrophe(nb_s, *form);
		nb_s = ft_check_accur(*form, nb_s);
		if ((*form).flag_plus && !ft_strchr(nb_s, '-'))
		{
			(*form).flag_space = 0;
			to_free = nb_s;
			nb_s = ft_strjoin("+", nb_s);
			ft_strdel(&to_free);
		}
		if ((*form).flag_space && !ft_strchr(nb_s, '-'))
		{
			to_free = nb_s;
			nb_s = ft_strjoin(" ", nb_s);
			ft_strdel(&to_free);
		}
		return (ft_print(*form, nb_s));
	}
	return (0);
}
