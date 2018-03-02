/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_accur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 09:53:43 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 10:46:24 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_accur(t_form form, char *str)
{
	size_t	size;
	char	*to_free;
	char	*res;

	size = form.accur - ft_strlen(str) + 1;
	res = (char *)malloc(sizeof(char) * size);
	res = ft_memset(res, '0', size);
	res[size - 1] = '\0';
	to_free = res;
	res = ft_strjoin(res, str);
	ft_strdel(&to_free);
	res = ft_push_char(res, '-', '0');
	ft_strdel(&str);
	return (res);
}
