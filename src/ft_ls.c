/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:34:32 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 11:29:56 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	ft_manage_lst(t_list **alst, t_flags flags, t_format format)
{
	ft_add_time(alst, flags);
	if (!flags.f)
	{
		ft_merge_sort_lex(alst, flags);
		ft_merge_sort_time(alst, flags);
		ft_add_size(alst);
		ft_merge_sort_size(alst, flags);
	}
	if (flags.r)
		ft_lstrev(alst);
	ft_print_files(*alst, flags);
	if (flags.l_r)
		ft_ls_recursive(*alst, flags, format);
	ft_lstdel(alst, ft_lstdelfunc);
}

static void	ft_if_err(char **path, char *new_path)
{
	ft_strdel(path);
	if (ft_strrchr(new_path, '/'))
		return (ft_error(ft_strrchr(new_path, '/') + 1));
	else
		return (ft_error(new_path));
}

void		ft_ls(char *new_path, t_flags flags, t_format format)
{
	DIR		*dir;
	t_list	*alst;
	char	*path;

	path = ft_strdup(new_path);
	dir = opendir(path);
	if (!dir && ft_is_dir(path))
		return (ft_if_err(&path, new_path));
	if (dir && !ft_is_link(new_path))
		alst = ft_lst_files(dir, &path);
	else
	{
		ft_get_file_data(path, flags, format);
		ft_strdel(&path);
		if (dir)
			closedir(dir);
		return ;
	}
	ft_manage_lst(&alst, flags, format);
	ft_strdel(&path);
	closedir(dir);
}
