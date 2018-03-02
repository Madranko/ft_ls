/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:23:12 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 10:30:25 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static t_format	ft_file_arg(t_list *alst, t_flags flags, t_format format)
{
	if (((char *)alst->content)[0] != '.' || flags.a)
		format = ft_make_format(format, alst);
	return (format);
}

static t_format	ft_path_arg(t_list *alst, t_flags flags, t_format format)
{
	if (*(ft_strrchr(alst->content, '/') + 1) != '.' || flags.a)
		format = ft_make_format(format, alst);
	return (format);
}

static t_format	ft_format_arg(t_list *alst, t_flags flags, t_format format)
{
	if (!ft_strchr(alst->content, '/'))
		return (ft_file_arg(alst, flags, format));
	else
		return (ft_path_arg(alst, flags, format));
}

int				ft_find_files(t_list *alst, t_flags flags, t_format format)
{
	int			ret;
	t_list		*tmp;
	struct stat	buf;

	ret = 0;
	tmp = alst;
	while (tmp)
	{
		if (!lstat(tmp->content, &buf) && (ft_is_file(tmp->content) ||
					ft_is_link(tmp->content)))
			format = ft_format_arg(tmp, flags, format);
		tmp = tmp->next;
	}
	while (alst)
	{
		if (!lstat(alst->content, &buf) && (ft_is_file(alst->content) ||
					ft_is_link(alst->content)))
		{
			ft_ls(alst->content, flags, format);
			ret++;
			ft_printf("\n");
		}
		alst = alst->next;
	}
	return (ret);
}
