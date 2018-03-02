/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width_unicode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:00:20 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:01:02 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_invalid_accur(t_form form)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (form.width + 1));
	if (form.flag_minus)
		res = ft_memset(res, ' ', form.width);
	else
	{
		if (form.flag_zero)
			res = ft_memset(res, '0', form.width);
		else
			res = ft_memset(res, ' ', form.width);
	}
	res[form.width] = '\0';
	return (res);
}

static char		*ft_fill_res(t_form form, char *res, size_t size)
{
	if (form.flag_minus)
		res = ft_memset(res, ' ', size);
	else
	{
		if (form.flag_zero)
			res = ft_memset(res, '0', size);
		else
			res = ft_memset(res, ' ', size);
	}
	res[size] = '\0';
	return (res);
}

char			*ft_check_width_unicode(t_form form, unsigned char **str)
{
	char	*res;
	size_t	size;
	size_t	arr_size;

	if (form.width)
	{
		if (form.accur == -1)
			return (ft_invalid_accur(form));
		arr_size = ft_full_arr_strlen(str);
		if (form.width > arr_size)
		{
			size = form.width - arr_size;
			res = (char *)malloc(sizeof(char) * (size + 1));
			return (ft_fill_res(form, res, size));
		}
	}
	return (NULL);
}
