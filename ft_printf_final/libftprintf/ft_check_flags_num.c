/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 10:58:40 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:44:34 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_flags_num(t_form form, char *str)
{
	if (form.accur || form.flag_minus)
		form.flag_zero = 0;
	if (form.flag_zero)
	{
		str = ft_find_change(str, ' ', '0');
		str = ft_push_char(str, '-', '0');
		str = ft_push_x(str, '0');
	}
	return (str);
}
