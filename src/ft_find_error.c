/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:22:25 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 10:23:02 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_find_error(t_list *alst)
{
	t_list		*tmp;
	DIR			*dir;
	struct stat	buf;

	tmp = alst;
	while (tmp)
	{
		dir = opendir(tmp->content);
		if ((!dir && ft_is_dir(tmp->content)) || lstat(tmp->content, &buf))
			ft_error(tmp->content);
		tmp = tmp->next;
		if (dir)
			closedir(dir);
	}
}
