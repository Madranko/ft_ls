/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:22:50 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:22:58 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_type_search(char *str, t_form *form)
{
	(*form).type = '\0';
	if (str[0])
	{
		(*form).type = str[0];
		return (str + 1);
	}
	return (str);
}