/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:19:34 by mmotov            #+#    #+#             */
/*   Updated: 2018/01/01 13:23:56 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_check_width_s(t_form form, char *str)
{
	char	*res;
	size_t	size;

	if (form.width > ft_strlen(str) || (form.width && form.accur == -1))
	{
		if (form.accur == -1)
		{
			size = form.width;
			res = (char *)malloc(sizeof(char) * size + 1);
			if (form.flag_zero && !form.flag_minus)
				res = ft_memset(res, '0', size);
			else
				res = ft_memset(res, ' ', size);
			res[size] = '\0';
			ft_strdel(&str);
			return (res);
		}
	}
	str = ft_check_width_str(form, str);
	return (str);
}

static int	ft_null(t_form form, char *nb_s)
{
	int		ret;

	nb_s = ft_strdup("(null)");
	nb_s = ft_check_accur_str(form, nb_s);
	nb_s = ft_check_width_s(form, nb_s);
	ft_putstr(nb_s);
	ret = (int)ft_strlen(nb_s);
	ft_memdel((void **)&nb_s);
	return (ret);
}

int			ft_str_string(t_form *form, va_list ap)
{
	char	*nb_s;
	int		ret;

	if ((*form).type == 's')
	{
		if ((*form).size && !ft_strcmp((*form).size, "l"))
		{
			(*form).type = 'S';
			return (0);
		}
		if (!(nb_s = ft_strdup(va_arg(ap, char *))))
			return (ft_null(*form, nb_s));
		nb_s = ft_check_accur_str(*form, nb_s);
		nb_s = ft_check_width_s(*form, nb_s);
		ft_putstr(nb_s);
		ret = (int)ft_strlen(nb_s);
		ft_strdel(&nb_s);
		return (ret);
	}
	return (0);
}
