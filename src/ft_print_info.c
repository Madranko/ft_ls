/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:45:08 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 11:35:21 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static char	*ft_converter(struct stat buf, int base)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 4);
	str = ft_memset(str, '-', 3);
	str[3] = '\0';
	if (buf.st_mode & 04 * base)
		str[0] = 'r';
	if (buf.st_mode & 02 * base)
		str[1] = 'w';
	if ((buf.st_mode & S_ISUID) && base == 0100)
		str[2] = (buf.st_mode & S_IXUSR) ? 's' : 'S';
	else if ((buf.st_mode & S_ISGID) && base == 010)
		str[2] = (buf.st_mode & S_IXGRP) ? 's' : 'S';
	else if ((buf.st_mode & S_ISVTX) && base == 01)
		str[2] = (buf.st_mode & S_IXOTH) ? 't' : 'T';
	else if (buf.st_mode & 01 * base)
		str[2] = 'x';
	return (str);
}

void		ft_print_mode(struct stat buf)
{
	char	*user;
	char	*group;
	char	*other;

	user = ft_converter(buf, 0100);
	group = ft_converter(buf, 010);
	other = ft_converter(buf, 01);
	ft_printf("%s%s%s", user, group, other);
	ft_strdel(&user);
	ft_strdel(&group);
	ft_strdel(&other);
}

void		ft_print_type(mode_t mode)
{
	if (S_ISBLK(mode))
		ft_printf("b");
	else if (S_ISCHR(mode))
		ft_printf("c");
	else if (S_ISDIR(mode))
		ft_printf("d");
	else if (S_ISFIFO(mode))
		ft_printf("p");
	else if (S_ISLNK(mode))
		ft_printf("l");
	else if (S_ISREG(mode))
		ft_printf("-");
}

void		ft_print_link(char *path)
{
	struct stat	sb;
	char		*linkname;

	lstat(path, &sb);
	linkname = malloc((size_t)sb.st_size + 1);
	readlink(path, linkname, (size_t)sb.st_size + 1);
	linkname[sb.st_size] = '\0';
	ft_printf(" -> %s", linkname);
	ft_strdel(&linkname);
}

void		ft_print_info(t_list *alst, t_format format, t_flags flags)
{
	struct stat		buf;
	struct passwd	*user;
	struct group	*group;

	lstat(alst->content, &buf);
	group = getgrgid(buf.st_gid);
	user = getpwuid(buf.st_uid);
	ft_print_type(buf.st_mode);
	ft_print_mode(buf);
	if (ft_ext_atribute(alst->content))
		ft_printf("%*d %-*s%", format.link_len - 1, buf.st_nlink,
				format.name_len, user->pw_name);
	else
		ft_printf("%*d %-*s%", format.link_len, buf.st_nlink, format.name_len,
				user->pw_name);
	ft_printf("%-*s", format.group_len, group->gr_name);
	ft_printf("%*d", format.size_len, buf.st_size);
	if (flags.l_u)
		ft_print_time(buf.st_birthtimespec, flags);
	else if (flags.u)
		ft_print_time(buf.st_atimespec, flags);
	else
		ft_print_time(buf.st_mtimespec, flags);
}
