/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:37:10 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 10:38:03 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_list	*ft_make_node(char *dir_name, struct dirent *entry, char **path)
{
	char	*to_free;
	t_list	*alst;

	if (!ft_is_link(dir_name) && ft_is_dir(dir_name))
	{
		to_free = *path;
		*path = ft_strjoin(*path, entry->d_name);
		ft_strdel(&to_free);
	}
	else
	{
		to_free = *path;
		*path = ft_strdup(dir_name);
		ft_strdel(&to_free);
	}
	alst = ft_lstnew(*path, ft_strlen(*path) + 1);
	((char *)alst->content)[ft_strlen(*path)] = '\0';
	return (alst);
}

t_list	*ft_lst_files(DIR *dir, char **dir_name)
{
	struct dirent	*entry;
	t_list			*alst;
	t_list			*newlst;
	char			*path;
	char			*to_free;

	alst = NULL;
	if ((entry = readdir(dir)))
	{
		to_free = *dir_name;
		*dir_name = ft_strjoin(*dir_name, "/");
		ft_strdel(&to_free);
		path = ft_strdup(*dir_name);
		alst = ft_make_node(*dir_name, entry, &path);
		ft_strdel(&path);
	}
	while ((entry = readdir(dir)))
	{
		path = ft_strdup(*dir_name);
		newlst = ft_make_node(*dir_name, entry, &path);
		ft_lstadd_end(&alst, newlst);
		ft_strdel(&path);
	}
	return (alst);
}
