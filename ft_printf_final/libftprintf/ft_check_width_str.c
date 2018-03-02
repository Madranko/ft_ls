/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 10:59:36 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:00:11 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_width_str(t_form form, char *str)
{
	char	*res;
	size_t	size;
	char	*to_free;

	if (form.width > ft_strlen(str))
	{
		size = form.width - ft_strlen(str) + 1;
		res = (char *)malloc(sizeof(char) * size);
		if (form.flag_zero && !form.flag_minus)
			res = ft_memset(res, '0', size);
		else
			res = ft_memset(res, ' ', size);
		res[size - 1] = '\0';
		to_free = res;
		if (form.flag_minus)
			res = ft_strjoin(str, res);
		else
			res = ft_strjoin(res, str);
		ft_strdel(&to_free);
		ft_strdel(&str);
		return (res);
	}
	return (str);
}
