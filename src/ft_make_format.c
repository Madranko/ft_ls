/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:38:46 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 10:39:05 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_format	ft_make_format(t_format format, t_list *alst)
{
	struct passwd	*user;
	struct group	*group;
	struct stat		buf;

	if (!lstat(alst->content, &buf))
	{
		user = getpwuid(buf.st_uid);
		group = getgrgid(buf.st_gid);
		if (format.link_len < ft_int_len(buf.st_nlink) + 2)
			format.link_len = ft_int_len(buf.st_nlink) + 2;
		if (format.name_len < (int)ft_strlen(user->pw_name) + 2)
			format.name_len = (int)ft_strlen(user->pw_name) + 2;
		if (format.size_len < ft_int_len((size_t)buf.st_size))
			format.size_len = ft_int_len((size_t)buf.st_size);
		if (format.group_len < (int)ft_strlen(group->gr_name) + 2)
			format.group_len = (int)ft_strlen(group->gr_name) + 2;
	}
	return (format);
}
