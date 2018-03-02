/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:03:12 by mmotov            #+#    #+#             */
/*   Updated: 2018/01/01 13:33:32 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flags_search(char *str, t_form *form)
{
	int		i;

	i = 0;
	while ((str[i] == '+' || str[i] == '-' || str[i] == ' ' || str[i] == '#' ||
	str[i] == '0' || str[i] == '\'') && ft_end_form(str[i]) && str[i] != '\0')
	{
		if (str[i] == '+')
			(*form).flag_plus = 1;
		if (str[i] == '-')
			(*form).flag_minus = 1;
		if (str[i] == ' ')
			(*form).flag_space = 1;
		if (str[i] == '#')
			(*form).flag_octorp = 1;
		if (str[i] == '0')
			(*form).flag_zero = 1;
		if (str[i] == '\'')
			(*form).flag_apost = 1;
		i++;
	}
	return (str + i);
}
