/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_accur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 10:46:58 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 10:47:16 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_accur(t_form form, char *str)
{
	char	*res;

	if (form.accur == -1 && !ft_strcmp(str, "0"))
	{
		res = ft_strdup("\0");
		ft_strdel(&str);
		return (res);
	}
	if (ft_strchr(str, '-'))
		form.accur++;
	if (form.accur == 0)
		return (str);
	if (form.accur > (int)ft_strlen(str))
		return (ft_add_accur(form, str));
	return (str);
}
