/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:20:29 by mmotov            #+#    #+#             */
/*   Updated: 2018/01/01 13:57:00 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t			**ft_check_size(va_list ap)
{
	wchar_t	*uni_str;
	wchar_t	**res;
	wchar_t	*to_free;
	int		i;
	int		len;

	len = 0;
	i = 0;
	uni_str = va_arg(ap, wchar_t *);
	if (!uni_str)
		return (NULL);
	while (uni_str[len])
		len++;
	res = (wchar_t **)malloc(sizeof(wchar_t*) * (len + 1));
	while (uni_str[i])
	{
		to_free = (wchar_t *)ft_make_unicode((unsigned int)uni_str[i]);
		res[i] = (wchar_t *)ft_strdup((char *)to_free);
		ft_memdel((void **)&to_free);
		i++;
	}
	res[i] = NULL;
	return (res);
}

static unsigned char	**ft_check_accur_str_uni(t_form form,
						unsigned char **arr)
{
	int		i;

	i = 0;
	if (form.accur > 0 && arr)
	{
		while (arr[i])
		{
			if (form.accur < (int)ft_strlen((const char *)arr[i]))
			{
				ft_memdel((void**)&arr[i]);
				i++;
				while (arr[i])
				{
					ft_memdel((void**)&arr[i]);
					i++;
				}
				break ;
			}
			form.accur = form.accur - (int)ft_strlen((const char *)arr[i]);
			i++;
		}
	}
	return (arr);
}

static int				ft_null(t_form form)
{
	int		i;
	char	*res;

	res = ft_strdup("(null)");
	res = ft_check_accur_str(form, res);
	res = ft_check_width_str(form, res);
	ft_putstr(res);
	i = (int)ft_strlen(res);
	ft_strdel(&res);
	return (i);
}

static size_t			ft_print_u(t_form form, unsigned char **str)
{
	int		i;
	char	*res;
	size_t	size;

	i = 0;
	size = 0;
	res = ft_check_width_unicode(form, str);
	if (form.flag_minus && form.accur != -1)
	{
		while (str[i])
			ft_print_unicode(str[i++]);
		if (res)
			ft_putstr(res);
	}
	else
	{
		if (res)
			ft_putstr(res);
		while (str[i] && form.accur != -1)
			ft_print_unicode(str[i++]);
	}
	if (res)
		size = ft_strlen(res);
	ft_strdel(&res);
	return (size);
}

int						ft_str_string_unicode(t_form *form, va_list ap)
{
	unsigned char	**str;
	int				i;
	size_t			size;

	i = 0;
	if ((*form).type == 'S')
	{
		str = (unsigned char **)ft_check_size(ap);
		str = ft_check_accur_str_uni(*form, str);
		if (!str)
			return (ft_null(*form));
		else
		{
			size = ft_print_u(*form, str);
			if ((*form).accur != -1)
				i = (int)ft_full_arr_strlen(str);
			ft_del_arr(str);
			return ((int)(size + i));
		}
	}
	return (0);
}
