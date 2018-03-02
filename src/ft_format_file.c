/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:30:38 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 10:31:15 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static t_format	ft_file(t_list *alst, t_flags flags)
{
	t_format	format;

	format = ft_init_format();
	while (alst)
	{
		if (((char *)alst->content)[0] != '.' || flags.a)
			format = ft_make_format(format, alst);
		alst = alst->next;
	}
	return (format);
}

static t_format	ft_path(t_list *alst, t_flags flags)
{
	t_format	format;

	format = ft_init_format();
	while (alst)
	{
		if (*(ft_strrchr(alst->content, '/') + 1) != '.' || flags.a)
			format = ft_make_format(format, alst);
		alst = alst->next;
	}
	return (format);
}

t_format		ft_format_file(t_list *alst, t_flags flags)
{
	if (!ft_strchr(alst->content, '/'))
		return (ft_file(alst, flags));
	else
		return (ft_path(alst, flags));
}
