/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_accur_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 09:56:39 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 10:58:21 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_accur_str(t_form form, char *str)
{
	char	*res;

	if (form.accur == -1)
	{
		ft_strdel(&str);
		res = ft_strdup("\0");
		return (res);
	}
	if (form.accur == 0)
		return (str);
	res = ft_strnew(form.accur);
	res = ft_strncpy(res, str, form.accur);
	ft_strdel(&str);
	return (res);
}
