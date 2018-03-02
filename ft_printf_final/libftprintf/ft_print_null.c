/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:11:22 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:13:30 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_add_width(t_form form, char *str)
{
	if (form.flag_minus)
	{
		str = ft_memset(str, ' ', form.width - 1);
		ft_putchar('\0');
		ft_putstr(str);
	}
	else
	{
		if (form.flag_zero)
			str = ft_memset(str, '0', form.width - 1);
		else
			str = ft_memset(str, ' ', form.width - 1);
		ft_putstr(str);
		ft_putchar('\0');
	}
	return (str);
}

int				ft_print_null(t_form form)
{
	char	*str;
	int		ret;

	if (form.width)
	{
		str = (char *)malloc(sizeof(char) * form.width);
		str[form.width - 1] = '\0';
		str = ft_add_width(form, str);
		ret = (int)ft_strlen(str) + 1;
		ft_strdel(&str);
		return (ret);
	}
	else
	{
		ft_putchar('\0');
		return (1);
	}
}
