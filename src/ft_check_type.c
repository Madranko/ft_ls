/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:20:32 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 11:28:15 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		ft_is_dir(char *path)
{
	struct stat	buf_info;

	if (!lstat(path, &buf_info))
	{
		if (S_ISDIR(buf_info.st_mode))
			return (1);
	}
	return (0);
}

int		ft_is_file(char *path)
{
	struct stat	buf_info;

	lstat(path, &buf_info);
	if (S_ISREG(buf_info.st_mode))
		return (1);
	return (0);
}

int		ft_is_link(char *path)
{
	struct stat	buf_info;

	lstat(path, &buf_info);
	if (S_ISLNK(buf_info.st_mode))
		return (1);
	return (0);
}
