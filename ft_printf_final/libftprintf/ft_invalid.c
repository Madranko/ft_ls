/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:06:11 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:43:24 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_str_invalid(t_form *form)
{
	char	*str;
	int		ret;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = (*form).type;
	str[1] = '\0';
	str = ft_check_width_str(*form, str);
	ret = (int)ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (ret);
}
