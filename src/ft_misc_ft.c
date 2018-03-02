/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:42:51 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 10:43:42 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_add_size(t_list **alst)
{
	struct stat	buf;
	t_list		*tmp;

	tmp = *alst;
	while (tmp)
	{
		lstat(tmp->content, &buf);
		tmp->content_size = (size_t)buf.st_size;
		tmp = tmp->next;
	}
}

void	ft_add_time(t_list **alst, t_flags flags)
{
	struct stat	buf;
	t_list		*tmp;

	tmp = *alst;
	while (tmp)
	{
		lstat(tmp->content, &buf);
		if (flags.l_u)
			tmp->content_size = (size_t)buf.st_birthtimespec.tv_sec;
		else if (flags.u)
			tmp->content_size = (size_t)buf.st_atimespec.tv_sec;
		else
			tmp->content_size = (size_t)buf.st_mtimespec.tv_sec;
		tmp = tmp->next;
	}
}

void	ft_error(char *file)
{
	ft_putstr_fd("ls: ", 2);
	perror(file);
}

int		ft_ext_atribute(char *file)
{
	if (listxattr(file, NULL, 0, XATTR_NOFOLLOW) > 0)
	{
		ft_printf("@");
		return (1);
	}
	return (0);
}

int		ft_int_len(unsigned long long int nb)
{
	int		i;

	i = 1;
	while ((nb = nb / 10))
		i++;
	return (i);
}
