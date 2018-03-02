/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:10:50 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:11:09 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_flags_perc(t_form form, char *str)
{
	if (form.flag_minus)
		form.flag_zero = 0;
	if (form.flag_zero)
	{
		str = ft_find_change(str, ' ', '0');
		str = ft_push_char(str, '-', '0');
		str = ft_push_x(str, '0');
	}
	return (str);
}

int		ft_str_percent(t_form *form)
{
	char	*nb_s;
	int		ret;

	if ((*form).type == '%')
	{
		nb_s = (char *)malloc(sizeof(char) * 2);
		nb_s[0] = '%';
		nb_s[1] = '\0';
		nb_s = ft_check_width_num(*form, nb_s);
		nb_s = ft_check_flags_perc(*form, nb_s);
		ft_putstr(nb_s);
		ret = (int)ft_strlen(nb_s);
		ft_strdel(&nb_s);
		return (ret);
	}
	return (0);
}
