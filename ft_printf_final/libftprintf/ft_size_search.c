/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:17:41 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:36:35 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_hh_ll(char *str, t_form *form, size_t i)
{
	if (ft_strnstr(str, "hh", i))
	{
		(*form).size = ft_strdup("hh");
		return (str + 2);
	}
	else if (ft_strnstr(str, "ll", i))
	{
		(*form).size = ft_strdup("ll");
		return (str + 2);
	}
	else
		return (NULL);
}

char		*ft_size_search(char *str, t_form *form)
{
	size_t	i;

	i = 0;
	while (ft_end_form(str[i]) && str[i] != '\0')
		i++;
	if (ft_hh_ll(str, form, i))
		return (str + 2);
	else if (ft_strnstr(str, "l", i))
		(*form).size = ft_strdup("l");
	else if (ft_strnstr(str, "h", i))
		(*form).size = ft_strdup("h");
	else if (ft_strnstr(str, "j", i))
		(*form).size = ft_strdup("j");
	else if (ft_strnstr(str, "z", i))
		(*form).size = ft_strdup("z");
	else
	{
		(*form).size = NULL;
		return (str);
	}
	return (str + 1);
}
