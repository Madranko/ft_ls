/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:36:13 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 10:36:57 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static int	ft_is_dot(char *file_path, t_flags flags)
{
	char	*file_name;

	if (ft_strrchr(file_path, '/'))
	{
		file_name = ft_strrchr(file_path, '/') + 1;
		if (ft_strcmp(file_name, ".") && ft_strcmp(file_name, "..") &&
				(file_name[0] != '.' || flags.a))
			return (0);
		else
			return (1);
	}
	else
	{
		if ((ft_strcmp(file_path, ".") && ft_strcmp(file_path, "..")) ||
				(file_path[0] != '.' || flags.a))
			return (0);
		else
			return (1);
	}
}

void		ft_ls_recursive(t_list *alst, t_flags flags, t_format format)
{
	t_list	*tmp;
	char	*new_path;

	tmp = alst;
	while (tmp)
	{
		if (ft_is_dir(tmp->content) && !ft_is_dot(tmp->content, flags))
		{
			if (!ft_is_link(tmp->content))
			{
				new_path = ft_strdup(tmp->content);
				ft_printf("\n%s:\n", new_path);
				ft_ls(new_path, flags, format);
				ft_strdel(&new_path);
			}
		}
		tmp = tmp->next;
	}
}
