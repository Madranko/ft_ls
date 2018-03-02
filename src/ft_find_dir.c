/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:21:50 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 10:22:13 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_find_dir(t_list *alst, t_flags flags, t_format format, int if_file)
{
	t_list	*tmp;
	DIR		*dir;
	int		i;

	i = 0;
	tmp = alst;
	while (tmp)
	{
		dir = opendir(tmp->content);
		if (ft_is_dir(tmp->content) && dir)
		{
			if (if_file)
				ft_printf("\n");
			if_file = 0;
			if (i)
				ft_printf("\n");
			if (flags.argc)
				ft_printf("%s:\n", tmp->content);
			ft_ls(tmp->content, flags, format);
			i++;
			closedir(dir);
		}
		tmp = tmp->next;
	}
}
